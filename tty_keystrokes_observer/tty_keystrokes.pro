TEMPLATE = app
#CONFIG += console c++latest
CONFIG += console c++20
CONFIG += warn_on
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        tty.cpp \
        main.cpp

HEADERS += \
    subject_i.hpp \
    tty.hpp


QMAKE_CXXFLAGS += \
        # -std=c++2b 		\
        # -Wno-comment 		\
        # -Wno-uninitialized 	\
        # -Wno-reorder 		\
        # -Wno-unused-parameter 	\

