#pragma once
#include <algorithm>
#include <functional>
#include <memory>
#include <mutex>
#include <utility>
#include <vector>

template <typename T>
class Broadcaster {
    std::vector<std::reference_wrapper<T>>  _receivers{};
    mutable std::mutex                      _receivers_mutex{};
public:
	virtual ~Broadcaster() = default;

    void attach_receiver(T& receiver) {
        std::lock_guard {_receivers_mutex};
		_receivers.push_back(receiver);
	}

    void detach_receiver(T& receiver) {
        std::lock_guard {_receivers_mutex};
		std::erase_if(_receivers, [&](auto& check) {
			return std::addressof(check.get()) == std::addressof(receiver);
		});
	}
protected:
    template <typename ...TArgs>
    void broadcast( void(T::*fn)(TArgs ...)    ,   TArgs&& ...args) {
        std::lock_guard {_receivers_mutex};
		std::for_each(std::begin(_receivers), std::end(_receivers), [&](auto& receiver) {
			std::invoke(fn, receiver, std::forward<TArgs>(args)...);
		});
	}

    template <typename ...TArgs>
    void broadcast( void(T::*fn)(TArgs ...) const, TArgs&& ...args) const {
        std::lock_guard {_receivers_mutex};
		std::for_each(std::cbegin(_receivers), std::cend(_receivers), [&](const auto& receiver) {
			std::invoke(fn, receiver, std::forward<TArgs>(args)...);
		});
	}
};
