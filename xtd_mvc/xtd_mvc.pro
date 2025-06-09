# Copyright (c) Grant Rostig, grantrostig.com, Boost 1.0 license
 TEMPLATE = app                 # comment out these 3,
 SOURCES  = main.cpp           # we add SOURCES others below.
 CONFIG +=  console
 CONFIG -= app_bundle
 CONFIG -= qt

QMAKE_CXXFLAGS += \                     #https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/
    -std=c++23		            \
    -g3 		                \
    -O0 		                \
    -pedantic                   \
    -pedantic-errors            \
    -Wall   		            \       # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html \
    -Wextra   		            \

LIBS += \                               # https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Link-Options.html
    -lpthread                   \
    -lrt                        \
    -lstdc++exp                 \
                                \
HEADERS +=                      \
    controller.hpp \
    global_entities.hpp         \
    main_form.hpp \
    model.hpp \
    ut.hpp                      \

SOURCES +=                      \
    global_entities.cpp         \
