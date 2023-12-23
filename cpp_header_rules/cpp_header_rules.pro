TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        client_use.cpp \
        main.cpp \
        my_api.cpp

HEADERS += \
    client_use.hpp \
    my_api.hpp
