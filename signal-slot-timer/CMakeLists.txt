cmake_minimum_required(VERSION 3.5)
project(signal_slot_timer)

set(CMAKE_CXX_STANDARD 20)
include_directories(src, lib)
add_executable(signal_slot_timer
        src/STimer.h
        src/STimer.cpp
        src/main.cpp
        src/TimerUesr.h)
