TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

LIBS += \
        -lboost_system \
        -pthread \
            #-lasio \
            #-lbeast
            #-llib-asio \
            #-llib-beast
