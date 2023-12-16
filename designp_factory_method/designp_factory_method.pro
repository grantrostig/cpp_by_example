TEMPLATE = app
CONFIG += console c++latest
#CONFIG += console c++20
CONFIG += warn_on
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        #main.cpp \
        main_short.cpp \

HEADERS += \

QMAKE_CXXFLAGS += \
        # -std=c++2b 		\
         -std=gnu++23 		\
        # -Wno-comment 		\
        # -Wno-uninitialized 	\
        # -Wno-reorder 		\
        # -Wno-unused-parameter 	\

STATECHARTS += \
    gr_state_chart.scxml

DISTFILES += \
    gr_model.qmodel

