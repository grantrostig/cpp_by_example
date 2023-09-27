cmake_minimum_required(VERSION 3.5)

project(std_template_deduction LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(std_template_deduction main.cpp)
