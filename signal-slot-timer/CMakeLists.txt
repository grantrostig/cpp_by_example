cmake_minimum_required(VERSION 3.5)
project(signal_slot_timer)

set(CMAKE_CXX_STANDARD 20)
include_directories(src, lib)
find_package( Boost 1.78 )
#find_package(Boost 1.78 COMPONENTS program_options REQUIRED)

add_executable(signal_slot_timer
        src/Feeding_chime.h
        src/Feeding_chime.cpp
        src/main.cpp
        src/TimerUesr.h
        lib/fteng/signals.hpp)
#target_link_libraries(signal_slot_timer Boost::program_options)  # macOS
