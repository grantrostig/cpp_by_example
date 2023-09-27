project( std_new_delete_operator LANGUAGES CXX)

cmake_minimum_required( VERSION 3.5)
set( CMAKE_CXX_STANDARD 20)
set( CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options( -Wall -Wextra -pedantic -pedantic-errors -Wno-unused-variable )

add_executable( std_new_delete_operator main.cpp)
