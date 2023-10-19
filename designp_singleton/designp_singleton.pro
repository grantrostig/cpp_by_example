TEMPLATE = app
CONFIG += console c++latest
//CONFIG += console c++20
CONFIG += warn_on
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += \
        #-std=gnu++2b		\
        -g3 		        \
        -O0 		        \
        -Wall   		\  # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
        -Wextra   		\
        #-Wno-comment 		\
        #-Wno-unused-parameter 	\
        #-Wno-uninitialized 	\
        #-Wno-reorder 		\

SOURCES += \
        main.cpp \
        singleton_gof_derived_t_ref.cpp \
        singleton_gof_with_ptr.cpp

HEADERS += \
    singleton_gof_derived_t_ref.hpp \
    singleton_gof_with_ptr.hpp
