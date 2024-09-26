cmake_minimum_required(VERSION 3.16)

project(radio_spectrum_iostreams LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(radio_spectrum_iostreams main.cpp)

include(GNUInstallDirs)
install(TARGETS radio_spectrum_iostreams
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
