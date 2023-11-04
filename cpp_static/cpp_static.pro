TEMPLATE = app
CONFIG += console c++latest
CONFIG += warn_on
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    cpp_static_example.hpp \
    linkage.hpp \
    scope.hpp \
    storage_duration.hpp \

SOURCES += \
        cpp_static_example.cpp \
        linkage.cpp \
        scope.cpp \
        storage_duration.cpp \
        main.cpp \

