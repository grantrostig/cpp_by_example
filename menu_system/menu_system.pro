TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        action_detail_row.cpp \
        action_dialog.cpp \
#        action_io_row.cpp \
        actions.cpp \
        global_entities.cpp \
        interaction_result.cpp \
#        io_field.cpp \
#        io_row.cpp \
#        io_table.cpp \
        main.cpp \
        menu.cpp \
        menu_actions.cpp \
        menu_option.cpp \
        process_menu.cpp \
        state_application.cpp \
        state_menu.cpp \
        valid_values.cpp \
        window_panel.cpp

HEADERS += \
    action_detail_row.h \
    action_dialog.h \
#    action_io_row.h \
    actions.h \
    global_entities.h \
    interaction_result.h \
#    io_field.h \
#    io_row.h \
#    io_table.h \
    menu.h \
    menu_actions.h \
    menu_option.h \
    process_menu.h \
    state_application.h \
    state_menu.h \
    valid_values.h \
    window_panel.h

QMAKE_CXXFLAGS += \
        -std=c++2a

LIBS += \
        -lpthread \
        -lrt

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/release/ -llib_tty
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/debug/ -llib_tty
else:unix: LIBS += -L$$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/ -llib_tty

INCLUDEPATH += $$PWD/../lib_tty
DEPENDPATH += $$PWD/../lib_tty

# win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/release/liblib_tty.a
# else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/debug/liblib_tty.a
# else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/release/lib_tty.lib
# else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/debug/lib_tty.lib
# else:unix: PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/liblib_tty.a

unix: PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/liblib_tty.a
