QT += quick
CONFIG += c++11 console

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    Src/Logger.h \
    Src/LoggerTemplate.h

SOURCES += \
        Src/Logger.cpp \
        Src/main.cpp

RESOURCES += Qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

OTHER_FILES += README.md \
    .clang-format \
    LICENSE \
    appveyor.yml \
    .travis.yml
macos {
OTHER_FILES += \
    scripts/macos/install.sh \
    scripts/macos/build.sh
}

linux {
OTHER_FILES += \
    scripts/ubuntu/install.sh \
    scripts/ubuntu/build.sh \
}
