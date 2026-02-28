# Created by and for Qt Creator This file was created for editing the project sources only.
# grant: added compile and run for all? files
cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_COMPILE_WARNING_AS_ERROR OFF)

set (SRCS README.md
   MemoryCore/Accountant.cpp MemoryCore/Accountant.h
   MemoryCore/Accountant.cpp MemoryCore/Accountant.cpp
)
project(Singleton_memory_mangager)
add_executable(${CMAKE_PROJECT_NAME} ${SRCS}
   MemoryMangager/MemoryMangager.cpp
)
#   listings/listing_c.main.cpp)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
