# Añadir recursos al proyecto
RESOURCES += resources.qrc \
    resources.qrc

QT += core gui widgets

TARGET = Proyecto_Final
TEMPLATE = app

SOURCES += main.cpp \
           Game.cpp \
           Tank.cpp \
           Bullet.cpp \
           Enemy.cpp \
           Wall.cpp

HEADERS += Game.h \
           Tank.h \
           Bullet.h \
           Enemy.h \
           Wall.h

DISTFILES += \
    images/Fondo Tank battle city.png \
    images/Game Over Tank battle city.png \
    images/Proyectil tanque.png \
    images/Tanque _Enemigo.png \
    images/Tanque _Enemigo.png
