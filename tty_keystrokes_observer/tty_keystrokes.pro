TEMPLATE = app
#CONFIG += console c++latest
CONFIG += console c++20
CONFIG += warn_on
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        controller_loop.cpp \
        keystroke_events_i.cpp \
        observer.cpp \
        main.cpp \
        tty_keystroke_observer.cpp \
        tty_keystroke_subject.cpp \
        tty_logger.cpp

HEADERS += \
    controller_loop.hpp \
    keystroke_events_i.hpp \
    observer.hpp \
    subject.hpp \
    tty_keystroke_observer.hpp \
    tty_keystroke_subject.hpp \
    tty_logger.hpp

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

