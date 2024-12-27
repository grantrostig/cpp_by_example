cmake_minimum_required(VERSION 3.16)
project(cpp_output_adaptor LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_output_adaptor main.cpp)

include(GNUInstallDirs)
install(TARGETS cpp_output_adaptor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
