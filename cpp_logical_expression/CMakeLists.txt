cmake_minimum_required(VERSION 3.16)

project(cpp_logical_expression LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_logical_expression main.cpp)

include(GNUInstallDirs)
install(TARGETS cpp_logical_expression
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
