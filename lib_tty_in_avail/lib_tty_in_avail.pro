TEMPLATE = app
CONFIG += console
CONFIG += c++20
CONFIG += warn_on
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += \
#        -std=gnu++2b 		\
        -std=c++2b          \
#        -std=gnu++23 		 \
        -g3 		        \
        -O0 		        \
        -Wall   		    \  # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
        -Wextra   		    \
#        -Wno-comment 		    \
#        -Wno-reorder 		    \
#        -Wno-unused-function 	\
#        -Wno-unused-parameter 	\
#        -Wno-unused-variable 	\
#        -Wno-uninitialized 	\

SOURCES += \
        main.cpp
