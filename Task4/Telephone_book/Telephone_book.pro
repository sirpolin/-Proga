TEMPLATE = app
CONFIG += console
CONFIG -= qt
CONFIG -=debug
CONFIG +=debug_and_release build_all

    SOURCES += main.cpp \
    Book.cpp

QMAKE_CXXFLAGS += -std=gnu++0x

HEADERS += \
    Book.h
