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
    android/src/ca/riftekit/photofly/MyJavaClass.java

