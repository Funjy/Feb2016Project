QT += quick quickcontrols2 svg

android {
QT += androidextras
}

TEMPLATE = app
TARGET = PhotoFly

CONFIG += c++11

RESOURCES += qml.qrc
include(deployment.pri)

#DEFINES += QPM_INIT\\(E\\)=\"E.addImportPath(QStringLiteral(\\\"qrc:/\\\"));\"

#include(../resources/material/material.pri)

DEP_INCLUDES = \
    src

DEPENDPATH +=	$${DEP_INCLUDES}
INCLUDEPATH +=	$${DEP_INCLUDES}

HEADERS += \
    src/core/applicationsettings.h \    
    src/core/mainworker.h \
    src/models/photocontainer.h \
    src/models/registrationformdata.h \
    src/containers/serializationinfo.h \
    src/behaviours/iserializable.h \
    src/behaviours/iserviceprovider.h \
    src/photo_service/servicerequestfactory.h \
#    src/photo_service/loginrequest.h \
    src/photo_service/servicemessage.h \
    src/photo_service/genericservicemessage.h \
    src/behaviours/iimagegalleryprovider.h \
    src/photo_service/genericservicerequest.h \
    src/photo_service/serviceprovider.h \
    src/controllers/registrationformcontroller.h \
    src/controllers/mainformcontroller.h

SOURCES += \
    src/core/applicationsettings.cpp \
    src/main.cpp \
    src/core/mainworker.cpp \
    src/models/photocontainer.cpp \
    src/models/registrationformdata.cpp \
    src/containers/serializationinfo.cpp \
    src/photo_service/servicerequestfactory.cpp \
#    src/photo_service/loginrequest.cpp \
    src/photo_service/servicemessage.cpp \
    src/photo_service/genericservicemessage.cpp \
    src/photo_service/genericservicerequest.cpp \
    src/photo_service/serviceprovider.cpp \
    src/controllers/registrationformcontroller.cpp \
    src/controllers/mainformcontroller.cpp

android {
OTHER_FILES += \
    android/AndroidManifest.xml \
    android/res/values/libs.xml
    android/build.gradle

HEADERS += \
    src/core/imagepickerandroid.h \
    src/core/paymentandroid.h

SOURCES += \
    src/core/imagepickerandroid.cpp \
    src/core/paymentandroid.cpp

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

DISTFILES += \
    android/src/ca/riftekit/photofly/MyJavaClass.java \
#    android/src/ca/riftekit/photofly/MyPayment.java \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/ma_file.txt \
    saved_for_later_use/MyPayment.java
}
