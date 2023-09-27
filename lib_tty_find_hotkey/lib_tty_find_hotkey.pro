TEMPLATE = app
CONFIG += console
#TEMPLATE = lib
#CONFIG += staticlib

CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++latest
#CONFIG += c++20
CONFIG += warn_on
#CONFIG += thread

# ??CONFIG += QMAKE_CFLAGS_WARN_ON
# ??CONFIG += QMAKE_CXXFLAGS_WARN_ON

QMAKE_CXXFLAGS += \
        -std=gnu++2b		\
        -g3 		        \
        -O0 		        \
        -Wall   		\  # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
        -Wextra   		\
        #-Wno-comment 		\
        #-Wno-uninitialized 	\
        #-Wno-reorder 		\
        #-Wno-unused-parameter 	\

LIBS += \
        #-lpthread \
        #-lstdc++_libbacktrace \
        #-lrt

SOURCES += \
        main.cpp \

#INCLUDEPATH += $$PWD/../lib_tty
#DEPENDPATH += $$PWD/../lib_tty

win32:CONFIG(release, debug|release):       LIBS += -L$$PWD/../../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/release/ -llib_tty
else:win32:CONFIG(debug, debug|release):    LIBS += -L$$PWD/../../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/debug/   -llib_tty
else:unix:                                  LIBS += -L$$PWD/../../build-lib_tty-Desktop_Qt_6_5_2_GCC_64bit-Debug/          -llib_tty

