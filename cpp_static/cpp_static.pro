TEMPLATE = app
CONFIG += console c++latest
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cpp_static_example.cpp \
        main.cpp \
        scope.cpp \
        storage_duration.cpp

HEADERS += \
    cpp_static_example.h \
    scope.hpp \
    storage_duration.hpp
