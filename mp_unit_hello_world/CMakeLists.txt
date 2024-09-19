cmake_minimum_required(VERSION 3.16)

project(mp_unit_hello_world LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mp_unit_hello_world main.cpp)

include(GNUInstallDirs)
install(TARGETS mp_unit_hello_world
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
