#pragma once
#include <algorithm>
#include <functional>
#include <memory>
#include <mutex>
#include <utility>
#include <vector>

template <typename T>
class Subject_I {
    std::vector<std::reference_wrapper<T>>  _receivers{};
    mutable std::mutex                      _receivers_mutex{};
public:
    virtual ~Subject_I() = default;

    void attach_observer(T& receiver) {
        std::lock_guard {_receivers_mutex};
		_receivers.push_back(receiver);
	}

    void detach_observer(T& receiver) {
        std::lock_guard {_receivers_mutex};
		std::erase_if(_receivers, [&](auto& check) {
			return std::addressof(check.get()) == std::addressof(receiver);
		});
	}
protected:
    template <typename... TArgs>
    void notify( void(T::*fn)(TArgs ...)    ,   TArgs&& ...args) {
        std::lock_guard {_receivers_mutex};
        std::for_each(std::begin(_receivers), std::end(_receivers), [&](auto& receiver) {
            std::invoke(fn, receiver, std::forward<TArgs>(args)...);
        });
    }

//    template <typename... TArgs, typename F_type = std::function< void( TArgs&&... ) > >   // TODO??:
//    void broadcast( F_type fn, TArgs&&... args ) {
//        std::lock_guard {_receivers_mutex};
//        for( auto & r : _receivers ) {
//            std::invoke(fn, r, std::forward< TArgs >(args)... );
//        }
//    }

    template <typename ...TArgs>
    void notify( void(T::* const fn)(TArgs ...) const, TArgs&& ...args) const {
        std::lock_guard {_receivers_mutex};
        std::for_each(std::cbegin(_receivers), std::cend(_receivers), [&](const auto& receiver) {
            std::invoke(fn, receiver, std::forward<TArgs>(args)...);
        });
    }

//    template <typename... TArgs, typename F_type = std::function< void( TArgs&&... ) const> >   // TODO??:
//    void broadcast( F_type fn, TArgs&&... args ) const {
//        // static_assert( F_type  );  TODO??:
//        std::lock_guard {_receivers_mutex};
//        for( auto const & r : _receivers ) {
//            std::invoke(fn, r, std::forward< TArgs >(args)... );
//        }
//	}
};
