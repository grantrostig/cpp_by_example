TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

QMAKE_CXXFLAGS += \
        -std=c++2a \
        -Wno-comment \
        -Wno-uninitialized \
        -Wno-reorder \
        -Wno-unused-parameter \

LIBS += \
        -lpthread \
        -lrt \
        -lcryptopp \
        -L /home/grostig/libs/lib
