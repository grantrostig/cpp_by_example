#include <atomic>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <span>
//#include <new>

class Memory_used_tracker {
    std::atomic<size_t> current_memory_in_use_bytes{};  // Actually memory use is num_bytes + size_of(Quantity)
    Memory_used_tracker() : current_memory_in_use_bytes(0) {}
public:
    Memory_used_tracker(Memory_used_tracker const&) = delete;
    Memory_used_tracker& operator=(Memory_used_tracker const&) = delete;

    static auto& get_my_singleton()  {
static  Memory_used_tracker instance_singleton;
        return instance_singleton;
    }
    void add_to_current_usage_mem_bytes(std::size_t size) { current_memory_in_use_bytes += size; }
    void give_back_memory_bytes(std::size_t size)         { current_memory_in_use_bytes -= size; }
    auto how_much() const { return current_memory_in_use_bytes.load(); }
};

void* operator new(std::size_t num_bytes) {
//std::byte * operator new(std::size_t num_bytes) {
    //void * p_ptr { std::malloc(num_bytes + sizeof num_bytes)};  // Quantity and Memory
    std::size_t * p_ptr{ static_cast<std::size_t*>(std::malloc(num_bytes + sizeof num_bytes)) };  // Quantity and Memory
    if (p_ptr == nullptr) throw std::bad_alloc{};
    //std::size_t * q_ptr{ static_cast<std::size_t*>(p_ptr) };   // not void * anymore
    *p_ptr = num_bytes;                                          // first element is Quantity
    Memory_used_tracker::get_my_singleton().add_to_current_usage_mem_bytes(num_bytes);
    //return p_ptr + 1;
    // std::advance(), std::next() don't work since it is not a container.
    //std::span<size_t> my_span{p_ptr};
    //return my_span.subspan(1);
    return ++p_ptr;
    //return &(std::byte{});
}

//std::byte * operator new[](float num_bytes) {}
//std::byte * operator new[](std::string num_bytes) {}
void* operator new[](std::size_t num_bytes) {
    std::size_t * p_ptr { static_cast<std::size_t*>(std::malloc(num_bytes + sizeof num_bytes))};  // Quantity and Memory
    if (p_ptr == nullptr) throw std::bad_alloc{};
    *p_ptr = num_bytes;
    Memory_used_tracker::get_my_singleton().add_to_current_usage_mem_bytes(num_bytes);
    return ++p_ptr;
}
void operator delete(void* ptr) noexcept {
    if (ptr == nullptr) throw std::logic_error("nullptr");
    std::size_t * p_ptr{ static_cast<std::size_t*>(ptr) - 1 };
    Memory_used_tracker::get_my_singleton().give_back_memory_bytes(*p_ptr);
    std::free(p_ptr);
}
void operator delete[](void* ptr) noexcept {
    if (ptr == nullptr) return;
    std::size_t * p_ptr{ static_cast<std::size_t*>(ptr) - 1 };
    Memory_used_tracker::get_my_singleton().give_back_memory_bytes(*p_ptr);
    std::free(p_ptr);
}
// https://share.google/aimode/dElaHPnem1CfDTZ5Z
// https://share.google/aimode/zyFBYlhph5DYokuCn
// https://share.google/aimode/WTvhD1Boc9RqeUPXE

constexpr int my_value{3};
int main() {
    auto pre{ Memory_used_tracker::get_my_singleton().how_much() }; {
        int * p_ptr { new int{ my_value  } };  // need: 4 bytes on X86_64 (32 bits)
        int * q_ptr { new int[10]{0} };        // need: 10 * 4 bytes
        delete p_ptr;
    }
    auto post{ Memory_used_tracker::get_my_singleton().how_much() };
    if (post != pre) {
		std::cout << "Leaked " << post - pre << " bytes\n";
    }
    std::cout << "###\n";
}
