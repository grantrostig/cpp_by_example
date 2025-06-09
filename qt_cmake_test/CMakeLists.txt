cmake_minimum_required(VERSION 3.16)

project(qt_cmake_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(qt_cmake_test
    src/counter_controller.hpp src/counter_model.hpp src/main.cpp src/main_form.hpp)

include(GNUInstallDirs)
install(TARGETS qt_cmake_test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
