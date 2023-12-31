TEMPLATE = app
CONFIG += console
#CONFIG += console c++20
CONFIG += warn_on
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    #animals.cpp \
    main.cpp \
    main_shortened.cpp

HEADERS += \
    #animals.hpp

QMAKE_CXXFLAGS += \
        # -std=c++2b 		\
          -std=c++23 		\
        # -std=gnu++23 		\
        # -Wno-comment 		\
        # -Wno-uninitialized 	\
        # -Wno-reorder 		\
        # -Wno-unused-parameter 	\
        -O0 		            \
        -g3 		            \
        #-ggdb 		            \
        #-ggdb3 	            \
        -pedantic              \
        -pedantic-errors       \
        -Wall   		        \  # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
        -Wextra   		        \
        -Wdeprecated-declarations\
        -fconcepts              \

STATECHARTS += \
    gr_state_chart.scxml

DISTFILES += \
    gr_model.qmodel

