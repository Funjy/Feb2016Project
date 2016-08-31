QT += quick androidextras svg

TEMPLATE = app
TARGET = PhotoFly

SOURCES += main.cpp \
    mainworker.cpp \
    imagepickerandroid.cpp \
    registrationformdata.cpp \
    applicationsettings.cpp

RESOURCES += qml.qrc
include(deployment.pri)

DEFINES += QPM_INIT\\(E\\)=\"E.addImportPath(QStringLiteral(\\\"qrc:/\\\"));\"

include(../resources/material/material.pri)

HEADERS += \
    mainworker.h \
    imagepickerandroid.h \
    registrationformdata.h \
    applicationsettings.h

OTHER_FILES += \
    android/AndroidManifest.xml \
    android/res/values/libs.xml
    android/build.gradle \

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

DISTFILES += \
    android/src/ca/riftekit/photofly/MyJavaClass.java \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png

