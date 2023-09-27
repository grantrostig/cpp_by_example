TEMPLATE = app
#TEMPLATE = lib  # ?,per alan.
#CONFIG += staticlib  # ?, per alan.
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
#CONFIG += static  # just for qt stuff?
#CONFIG += static-runtime  # linux stuff separately?

SOURCES += \
        main.cpp

QMAKE_CXXFLAGS += \
        -std=c++2a

# QMAKE_LFLAGS += \
        # -static

LIBS += \
        -lpthread \
        -lrt

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/release/ -llib_tty
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/debug/ -llib_tty
#else:unix: LIBS += -L$$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/ -llib_tty
else:unix: LIBS += -L$$PWD/../build-lib_tty-Desktop_Qt_6_0_0_GCC_64bit-Debug/ -llib_tty

INCLUDEPATH += $$PWD/../lib_tty
DEPENDPATH += $$PWD/../lib_tty

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/release/liblib_tty.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/debug/liblib_tty.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/release/lib_tty.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/debug/lib_tty.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/liblib_tty.a

#unix: PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/liblib_tty.a
unix: PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_6_0_0_GCC_64bit-Debug/liblib_tty.a
