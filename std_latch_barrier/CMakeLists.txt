cmake_minimum_required(VERSION 3.16)

project(std_latch_barrier LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(std_latch_barrier main.cpp)

include(GNUInstallDirs)
install(TARGETS std_latch_barrier
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
