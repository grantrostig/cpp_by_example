#include <cstdlib>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <unordered_set>
#include <chrono>
#include <functional>

#define USE_INDEX
#define NDEBUG
#include <cassert>

using namespace std;

// ===== some simple timing boilerplate code
chrono::system_clock::time_point    time_start_1   {};
chrono::system_clock::time_point    time_start_2   {};
chrono::system_clock::time_point    time_end_1     {};
chrono::system_clock::time_point    time_end_2     {};
chrono::system_clock::duration      time_elapsed_1 {};
chrono::system_clock::duration      time_elapsed_2 {};
void print_timing() {
    time_elapsed_1 = time_end_1 - time_start_1;
    time_elapsed_2 = time_end_2 - time_start_2;
    cerr << " Duration1 ns: " << chrono::duration_cast<chrono::nanoseconds >(time_elapsed_1).count() << endl;
    //cerr << " Duration1 us: " << chrono::duration_cast<chrono::microseconds>(time_elapsed_1).count() << endl;
    //cerr << " Duration1 ms: " << chrono::duration_cast<chrono::milliseconds>(time_elapsed_1).count() << endl;
    cerr << " Duration2 ns: " << chrono::duration_cast<chrono::nanoseconds >(time_elapsed_2).count() << endl;
    //cerr << " Duration2 us: " << chrono::duration_cast<chrono::microseconds>(time_elapsed_2).count() << endl;
    //cerr << " Duration2 ms: " << chrono::duration_cast<chrono::milliseconds>(time_elapsed_2).count() << endl;
}

constexpr uint32_t CONTENT_SIZE = 1000;
//constexpr uint32_t MESSAGE_QTY =  100000;
constexpr uint32_t UNIQUENESS_DURATION_MINUTES = 1;
constexpr uint64_t MESSAGES_STREAMED_MAX = 1e6;
constexpr uint64_t NUM_MESSAGES_INTERVAL = 1e7;  // estimated number of message held during the uniqueness duration (interval).

using Binary_content = string;
using Point_in_time =  std::chrono::time_point<std::chrono::high_resolution_clock>;
using Message_hash_id =   size_t;

#ifdef USE_INDEX
using Messages_lookup_table =   unordered_set<Message_hash_id>;
#else
using Messages_lookup_table =   unordered_map<Message_hash_id, Point_in_time>;
#endif

struct Message {
    uint32_t length {CONTENT_SIZE};
    Binary_content binary_content;
    Message() {
        binary_content.reserve(CONTENT_SIZE);
        for (uint32_t i = 0; i < CONTENT_SIZE; ++i) {
            binary_content += static_cast<char>(255.0 * rand()/RAND_MAX);  // Ugly and slow, also: Warning: not very random, but we just need some junk data.
        }
    }
};

struct Buffer_struc {
    Point_in_time time_received {};
    Message_hash_id message_hash_id {};
};
using Messages_ordered = queue<Buffer_struc>;

#ifdef USE_INDEX  // not using overload to keep size/structure of program more similar.
void purge_old_messages(Messages_ordered & ordered_index, Messages_lookup_table & messages_lookup_table) {
    auto point_in_time = std::chrono::high_resolution_clock::now();
    while (ordered_index.front().time_received + std::chrono::minutes(UNIQUENESS_DURATION_MINUTES) < point_in_time) {
        auto message_hash_id = ordered_index.front().message_hash_id;
        messages_lookup_table.erase(message_hash_id);
        ordered_index.pop();
        // cerr << " Purge, ";
    }
    return;
}
#else
void purge_old_messages( Messages_lookup_table & messages_lookup_table ) {
    auto point_in_time = std::chrono::high_resolution_clock::now();
    for (auto it = messages_lookup_table.begin(); it != messages_lookup_table.end(); ++it) {
        if (it->second + std::chrono::minutes(UNIQUENESS_DURATION_MINUTES) < point_in_time) {
            messages_lookup_table.erase(it);
            // cerr << " Purge, ";
        }
    }
    return;
}
#endif

void calculate_message_metadata( Message const & message, Message_hash_id & message_hash_id, Point_in_time & point_in_time ) {
    static auto hash_function_object = std::hash<Binary_content> {};  // todo: Or make this global?
    message_hash_id =  hash_function_object(message.binary_content);
    point_in_time = std::chrono::high_resolution_clock::now();
}

#ifdef USE_INDEX  // not using overload to keep size/structure of program more similar.
bool update_uniqueness_index (Message const & message, Messages_ordered & ordered_index, Messages_lookup_table & messages_lookup_table) {
    // make a hash of large message and use that to test uniqueness
    Message_hash_id message_hash_id {};
    Point_in_time point_in_time {};
    calculate_message_metadata( message, message_hash_id, point_in_time );  // faster than using copy elision from function.

    // if unique add to history, else reject
    auto [v1, isInserted] = messages_lookup_table.insert(message_hash_id);
            if (!isInserted) {
        // cerr << " DUPLICATE, ";
        return false;
    }
    ordered_index.push(Buffer_struc {point_in_time, message_hash_id});  // no return value
    return true;
}
#else
bool update_uniqueness_index (Message const & message, Messages_lookup_table & messages_lookup_table) {
    // make a hash of large message and use that to test uniqueness
    auto hash_function_object = std::hash<Binary_content> {};
    Message_hash_id message_hash_id =  hash_function_object(message.binary_content);
    Point_in_time point_in_time = std::chrono::high_resolution_clock::now();

    // if unique add to history, else reject
    auto [v1, isInserted] = messages_lookup_table.insert({message_hash_id, point_in_time});
            if (!isInserted) {
        // cerr << " DUPLICATE, ";
        return false;
    }
    return true;
}

#endif

int main()
{
    Messages_ordered ordered_index {};  // stores unique valid messages ordered in time. used to quickly chop off aged out messages
    Messages_lookup_table messages_lookup_table {};  //
    messages_lookup_table.reserve(NUM_MESSAGES_INTERVAL);

    uint32_t iterations {};
    while (++iterations < MESSAGES_STREAMED_MAX) {
        Message message = Message {};
        // ===== test the uniqueness of the message and keep history of messages =====
        bool is_valid_message {false};

#ifdef USE_INDEX
#ifndef NDEBUG
        time_start_1 = chrono::system_clock::now();
#endif
        is_valid_message = update_uniqueness_index( message, ordered_index, messages_lookup_table );
#ifndef NDEBUG
        time_end_1 = chrono::system_clock::now();
#endif
        assert(is_valid_message);
        is_valid_message = update_uniqueness_index( message, ordered_index, messages_lookup_table );
        assert(!is_valid_message); // this message is a duplicate since we submitted it for a second time (within defined time interval), hence should be false.
#ifndef NDEBUG
        time_start_2 = chrono::system_clock::now();
#endif
        purge_old_messages( ordered_index, messages_lookup_table );
#ifndef NDEBUG
        time_end_2 = chrono::system_clock::now();
#endif
#else // USE_INDEX
#ifndef NDEBUG
        time_start_1 = chrono::system_clock::now();
#endif
        is_valid_message = update_uniqueness_index( message, messages_lookup_table );
#ifndef NDEBUG
        time_end_1 = chrono::system_clock::now();
#endif
        assert(is_valid_message);
        is_valid_message = update_uniqueness_index( message, messages_lookup_table );
        assert(!is_valid_message); // this message is a duplicate since we submitted it for a second time (within defined time interval), hence should be false.
#ifndef NDEBUG
        time_start_2 = chrono::system_clock::now();
#endif
        purge_old_messages( messages_lookup_table );
#ifndef NDEBUG
        time_end_2 = chrono::system_clock::now();
#endif
#endif  // USE_INDEX
#ifndef NDEBUG
        print_timing();
#endif
    }
    cout << "###" << endl;
    return 0;
}
