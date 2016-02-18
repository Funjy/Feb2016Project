QT += quick androidextras

SOURCES += main.cpp \
    mainworker.cpp \
    imagepickerandroid.cpp

RESOURCES += qml.qrc
include(deployment.pri)

HEADERS += \
    mainworker.h \
    imagepickerandroid.h

OTHER_FILES += \
    android/AndroidManifest.xml \
    android/res/values/libs.xml
    android/build.gradle \

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

DISTFILES += \
    android/src/org/riftekit/example/myandroidapp/MyJavaClass.java

