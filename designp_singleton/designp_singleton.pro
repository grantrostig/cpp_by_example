TEMPLATE = app
CONFIG += console
//CONFIG += console c++latest
//CONFIG += console c++20
CONFIG += warn_on
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += \
        -std=gnu++2b		\
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
        singleton_derived_t_ref.cpp \
        singleton_di.cpp \
        singleton_gof_registry.cpp \
        singleton_gof_t_decided_in_base_constr.cpp \
        singleton_gof_t_derived_link_time.cpp \
        singleton_gof_with_ptr.cpp

HEADERS += \
    singleton_derived_t_ref.hpp \
    singleton_di.hpp \
    singleton_gof_registry.hpp \
    singleton_gof_t_decided_in_base_constr.hpp \
    singleton_gof_t_derived_link_time.hpp \
    singleton_gof_with_ptr.hpp
