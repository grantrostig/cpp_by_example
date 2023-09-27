cmake_minimum_required(VERSION 3.5)

project(class_fully_defined LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -pedantic)

add_executable(class_fully_defined main.cpp)
