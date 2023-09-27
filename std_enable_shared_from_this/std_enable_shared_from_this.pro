TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += thread
QMAKE_LFLAGS += -static  # actually makes a static object.
#CONFIG += static wrong? why?

#if (!include(../../config.txt)) {
#	error("Failed to open config.txt")
#}

# // Compiler to use (comment out to use default one).
#QMAKE_CXX = clang++

QMAKE_CXXFLAGS += \
#            -std=c++17 \
#            -std=c++1z \
#            -std=gnu++17 \
#            -std=gnu++1z \
#            -std=c++2a \
#            -std=gnu++2a \
            -std=c++20 \
#            -std=gnu++20 \
#            -std=c++2b \
#            -std=gnu++2b \
            -Wall \
            -Wextra \
            -pedantic \
            -pedantic-errors \
#	         -Wno-unused-variable
            -Wno-unused-parameter \
#    	     -Wno-deprecated-declarations
#            -Weffc++ \
#            -fconcepts \
            -DBOOST_LOG_DYN_LINK \  		# on compile line not link line.
#            -DBOOST_SYSTEM_NO_DEPRECATED \  	# not sure what it does.

LIBS += \
        -lboost_system \
        -pthread \
        -lrt \
        -lssl \  #  missing this still: undefined reference to symbol 'd2i_PrivateKey_bio@@OPENSSL_1_1_0  related to: OPENSSL_API_COMPAT
        -lcrypto \  #  seems to be needed with -lssl
        -lboost_coroutine

SOURCES += \
        main.cpp
