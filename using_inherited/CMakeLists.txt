cmake_minimum_required(VERSION 3.5)

project(using_inherited LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 		20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(	-Wall -Wextra -pedantic -pedantic-errors  -Wno-unused-variable 	 )

add_executable(using_inherited main.cpp)
