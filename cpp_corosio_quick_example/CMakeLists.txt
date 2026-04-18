cmake_minimum_required(VERSION 3.16)

project(cpp_corosio_quick_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_corosio_quick_example main.cpp)

include(FetchContent)

FetchContent_Declare(capy
    GIT_REPOSITORY https://github.com/cppalliance/capy.git
    GIT_TAG develop
    GIT_SHALLOW TRUE)
FetchContent_Declare(corosio
    GIT_REPOSITORY https://github.com/cppalliance/corosio.git
    GIT_TAG develop
    GIT_SHALLOW TRUE)

FetchContent_MakeAvailable(capy corosio)

target_link_libraries( cpp_corosio_quick_example    Boost::corosio)
include(GNUInstallDirs)
install(TARGETS cpp_corosio_quick_example
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
