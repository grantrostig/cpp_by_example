# Copyright (c) Grant Rostig, grantrostig.com, Boost 1.0 license
# Either these three or the next 2, for app or lib, respectively.
#TEMPLATE = app                 # comment out these 3,
#SOURCES  = main.cpp            # we add other SOURCES below.
#CONFIG +=  console
 TEMPLATE = lib                 # OR comment out these 2.
 CONFIG +=  staticlib

 CONFIG -= app_bundle
 CONFIG -= qt

QMAKE_CXXFLAGS += \                     #https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/
   #-std=c++26		            \
    -std=c++23		            \
    -g3 		                \
    -O0 		                \
    -Wall   		            \       # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html \
    -Wextra   		            \

LIBS += \                               # https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Link-Options.html
    -lstdc++exp                 \

HEADERS += \
    global_entities.hpp         \
   #$$PWD/..h                   \   # probably wrong

SOURCES += \
    #NOT HERE main.cpp          \   # Declared above for app, and not declared above for lib.  Therefore do NOT declare it here in either case.
    cpp_headers.cpp.txt \
    global_entities.cpp         \


DISTFILES += \
    boost_headers.cpp.txt \
    cpp_headers.cpp.txt \
    example.pro.txt             \
    clang-format_grostig_qt.xml \
    CMakeLists.grostig.txt      \
    gnuplot-iostream.cpp.txt \
    grostig_tools_LONG.pro.txt  \
    grostig_tools_BRIEF.pro.txt \
    Makefile.txt                \
    README.txt                  \

DISTFILES += \
    boost_headers.hpp.txt       \
    catch_amalgamated.hpp.txt   \
    cpp_headers.hpp.txt         \
    gnuplot-iostream.hpp.txt \
    math_grostig.hpp.txt \
    ostream_joiner_gr.hpp.txt \
    random_toolkit.hpp.txt \
    ut.hpp                      \

DISTFILES += \
    catch_amalgamated.cpp.txt   \
    iostreams.cpp.txt \
    math_grostig.cpp.txt \
    ostream_joiner_gr.cpp.txt \
    random_toolkit.cpp.txt

####################################################
