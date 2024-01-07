TEMPLATE = app
CONFIG += console
CONFIG += c++latest
#CONFIG += console c++20
CONFIG += warn_on
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    01-traditional_implementation.cpp \
    02-modern_cpp_implementation.cpp \
    03-no_design_pattern.cpp \
    04-global_factory_functions.cpp \
    05-factory_member_functions.cpp \
    06-factory_function_objects.cpp \
    07-type_erasure_std-function.cpp \
    08-type_erasure_boost_typeerasure_1.cpp \
    09-type_erasure_boost_typeerasure_2.cpp \
    10-heap_factory_boost_factory.cpp \
    11-value_factory_boost_factory.cpp \
    12-handmade_function_class.cpp \
    13-handmade_any_class.cpp \
    13b-cppinsights.cpp \
    main.cpp \

HEADERS += \
    #animals.hpp

QMAKE_CXXFLAGS += \
        # -std=c++2b 		\
        # -std=c++23 		\
        # -std=gnu++23 		\
        # -Wno-comment 		\
        # -Wno-uninitialized 	\
        # -Wno-reorder 		\
        # -Wno-unused-parameter 	\
        -O0 		            \
        -g3 		            \
        #-ggdb 		            \
        #-ggdb3 	            \
        #-pedantic              \
        #-pedantic-errors       \
        #-Wall   		        \  # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
        #-Wextra   		        \
        #-Wdeprecated-declarations\
        -fconcepts              \

STATECHARTS += \
    gr_state_chart.scxml

DISTFILES += \
    gr_model.qmodel

