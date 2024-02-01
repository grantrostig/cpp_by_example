TEMPLATE = app
CONFIG += console latest
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp
        # Copyright (c) Grant Rostig, grantrostig.com, Boost 1.0 license
        # Snippet
        #CONFIG += c++latest
        #CONFIG += c++20

        TEMPLATE = app
        CONFIG += console
        #TEMPLATE = lib
        #CONFIG += staticlib
         CONFIG -= app_bundle
         CONFIG -= qt
         CONFIG += warn_on
         CONFIG += thread

        #TARGET = eigen_playground
        # ??CONFIG += QMAKE_CFLAGS_WARN_ON
        # ??CONFIG += QMAKE_CXXFLAGS_WARN_ON
        # // Compiler to use (comment out to use default one).
        #DEFINES =
        #QMAKE_LFLAGS += -static  # actually makes a static object.
        #CONFIG += static wrong? why?
        #QMAKE_CXX = clang++
        QMAKE_CXXFLAGS += \
                -std=c++23		    \
                #-std=gnu++23		    \
                -O0 		            \
                -g3 		            \
                #-ggdb 		            \
                #-ggdb3 	            \
                -fconcepts              \
                -fsanitize=undefined    \
                #-pedantic              \
                #-pedantic-errors       \
                -Wall   		        \  # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
                -Wextra   		        \
                -Wdeprecated-declarations\
                #-Weffc++               \
                #-Wno-comment 		    \
                #-Wno-uninitialized 	\
                #-Wno-reorder 		    \
                #-Wno-unused-parameter 	\
                #-Wno-unused-variable   \
                #-std=c++17             \
                #-std=gnu++17           \
                #-std=gnu++1z           \
                #-std=c++20             \
                #-std=gnu++20           \
                #-std=c++2a             \
                #-DBOOST_LOG_DYN_LINK   \  		# on compile line not link line.
                #-DBOOST_SYSTEM_NO_DEPRECATED \  	# not sure what it does.

        LIBS += \
                -lpthread               \
                -lrt                    \
                -lstdc++_libbacktrace   \
                #-lboost_system         \
                #-lboost_coroutine      \
                #-lssl                  \  #  missing this still: undefined reference to symbol 'd2i_PrivateKey_bio@@OPENSSL_1_1_0  related to: OPENSSL_API_COMPAT
                #-lcrypto \  #  seems to be needed with -lssl

        #INCLUDEPATH += $$PWD/../lib_tty
        #INCLUDEPATH += $$PWD/.
        #DEPENDPATH  += $$PWD/../lib_tty
        #SUBDIRS +=
        #if (!include(../../config.txt)) {
        #	error("Failed to open config.txt")
        #}

        HEADERS += \
            #boost_headers.h         \
            #cpp_headers.h           \
            #global_entities.h       \
            #gnuplot-iostream.h      \
            #KitchenSink.h           \
            #math_grostig.h          \
            #random_toolkit.h        \
        #   $$PWD/..h               \ # probably wrong

        SOURCES += \
            main.cpp \
            #iostreams.cpp \
            #global_entities.cpp \
            #random_toolkit.cpp \
        ####################################################
