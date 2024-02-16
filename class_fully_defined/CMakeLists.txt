# Grant Rostig copyright, License: Boost 1.0
# https://cmake.org/cmake/help/latest/command/add_link_options.html#command:add_link_options
# https://cmake.org/cmake/help/latest/manual/cmake-properties.7.html
# https://cmake.org/cmake/help/latest/manual/cmake-variables.7.html
# **** Commonly used method to build Cmake projects from the command line. ***
# cd project
# cmake -B build/
# cmake --build build --verbose
# cmake --build . --verbose
# make VERBOSE=1

cmake_minimum_required(VERSION 3.27)
#cmake_minimum_required(VERSION 3.9.6...3.15.0)

set(CMAKE_CXX_STANDARD 23)
if(CMAKE_CXX_STANDARD LESS 17)
   set(CMAKE_CXX_STANDARD 17)
endif()
# set_property(CMAKE_CXX_STANDARD 23)  #TODO??:
set(CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CXX_EXTENSIONS OFF)

include_directories( src, lib )
project(                class_fully_defined LANGUAGES CXX )
add_executable(         class_fully_defined src/main.cpp )
target_link_libraries(  class_fully_defined -lstdc++_libbacktrace )
#https://cmake.org/cmake/help/latest/command/add_link_options.html#command:add_link_options
# add_link_options( -lstdc++_libbacktrace  )  TODO??: Does NOT work.
#???string(APPEND CMAKE_EXE_LINKER_FLAGS " -fexceptions")

# new in 3.11 https://cmake.org/cmake/help/latest/prop_sf/COMPILE_OPTIONS.html#prop_sf:COMPILE_OPTIONS
set_source_files_properties(main.cpp PROPERTIES COMPILE_OPTIONS "-Wno-unused-parameter;-Wno-missing-field-initializer")

#https://cmake.org/cmake/help/latest/prop_sf/COMPILE_OPTIONS.html#prop_sf:COMPILE_OPTIONS
add_compile_options( -Wall -Wextra -pedantic -pedantic-errors -Wno-unused-variable
                      ) # -fsanitize=undefined)

set(CMAKE_VERBOSE_MAKEFILE ON)  # Doesn't seem to do anything ??
#add_compile_definitions("NO_DEBUG")

#find_package( Boost 1.81 )
#find_package(Boost 1.78 COMPONENTS program_options REQUIRED)


#target_link_libraries(<EXECUTABLE_NAME> Boost::program_options)  # macOS
