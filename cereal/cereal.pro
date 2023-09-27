TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

//INCLUDEPATH += $$PWD/../lib_tty
//DEPENDPATH += $$PWD/../lib_tty
INCLUDEPATH +=../../cereal/include/
