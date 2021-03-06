QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bomb.cpp \
    boss.cpp \
    bossbullet.cpp \
    bullet.cpp \
    enemybullet.cpp \
    enemyplane.cpp \
    main.cpp \
    mainscene.cpp \
    map.cpp \
    plane.cpp

HEADERS += \
    bomb.h \
    boss.h \
    bossbullet.h \
    bullet.h \
    config.h \
    enemybullet.h \
    enemyplane.h \
    mainscene.h \
    map.h \
    plane.h \
    sboss.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

CONFIG(debug,debug|release) {
    DESTDIR = $$absolute_path($${_PRO_FILE_PWD_}/bin/debug)
} else {
    DESTDIR = $$absolute_path($${_PRO_FILE_PWD_}/bin/release)
}
