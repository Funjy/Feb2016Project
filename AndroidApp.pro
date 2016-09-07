QT += quick androidextras svg

TEMPLATE = app
TARGET = PhotoFly

CONFIG += c++11

RESOURCES += qml.qrc
include(deployment.pri)

DEFINES += QPM_INIT\\(E\\)=\"E.addImportPath(QStringLiteral(\\\"qrc:/\\\"));\"

include(../resources/material/material.pri)

HEADERS += \
    mainworker.h \
    imagepickerandroid.h \
    models/registrationformdata.h \
    applicationsettings.h \
    models/photocontainer.h \
    behaviours/iserializable.h \
    containers/serializationinfo.h \
    paymentandroid.h

SOURCES += main.cpp \
    mainworker.cpp \
    imagepickerandroid.cpp \
    models/registrationformdata.cpp \
    applicationsettings.cpp \
    models/photocontainer.cpp \
    containers/serializationinfo.cpp \
    paymentandroid.cpp

OTHER_FILES += \
    android/AndroidManifest.xml \
    android/res/values/libs.xml
    android/build.gradle \

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

DISTFILES += \
    android/src/ca/riftekit/photofly/MyJavaClass.java \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/src/ca/riftekit/photofly/MyPayment.java

