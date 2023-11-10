TEMPLATE = app
CONFIG += console
CONFIG += c++latest
CONFIG += warn_on
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += \
        -std=gnu++23 		\
        -g3 		        \
        -O0 		        \
        -Wall   		    \  # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
        -Wextra   		    \
        -Wno-comment 		    \
        -Wno-reorder 		    \
        -Wno-unused-function 	\
        -Wno-unused-parameter 	\
        -Wno-unused-variable 	\
#        -Wno-uninitialized 	\

HEADERS += \
    cpp_static_example.hpp \
    global_entities.hpp \
    linkage.hpp \
    scope.hpp \
    scope_test.hpp \
    storage_duration.hpp \

SOURCES += \
    cpp_static_example.cpp \
    global_entities.cpp \
    linkage.cpp \
    main.cpp \
    scope.cpp \
    scope_test.cpp \
    storage_duration.cpp \

