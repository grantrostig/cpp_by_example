cmake_minimum_required(VERSION 3.5)

project(menu_without_visit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options( -Wall -Wextra -pedantic -pedantic-errors -Wno-unused-variable )

add_executable(menu_without_visit main.cpp)
