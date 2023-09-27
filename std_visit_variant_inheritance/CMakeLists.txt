cmake_minimum_required(VERSION 3.5)

project(std_visit_variant_inheritance LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -pedantic)

add_executable(std_visit_variant_inheritance main.cpp)
