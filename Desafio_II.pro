TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        eds.cpp \
        main.cpp \
        menu_eds.cpp \
        menu_principal.cpp \
        menu_red.cpp \
        menu_ventas.cpp \
        red_nacional.cpp \
        surtidor.cpp

HEADERS += \
    eds.h \
    menu_eds.h \
    menu_principal.h \
    menu_red.h \
    menu_ventas.h \
    red_nacional.h \
    surtidor.h
