TEMPLATE = app
#CONFIG += console c++latest
CONFIG += console c++20
CONFIG += warn_on
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        observer.cpp \
        tty.cpp \
        main.cpp \
        tty_controller.cpp

HEADERS += \
    observer.hpp \
    subject.hpp \
    tty.hpp \
    tty_controller.hpp

QMAKE_CXXFLAGS += \
        # -std=c++2b 		\
        # -Wno-comment 		\
        # -Wno-uninitialized 	\
        # -Wno-reorder 		\
        # -Wno-unused-parameter 	\

STATECHARTS += \
    gr_state_chart.scxml

DISTFILES += \
    gr_model.qmodel

