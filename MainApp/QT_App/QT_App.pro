QT += quick sql

SOURCES += \
        backend.cpp \
        main.cpp \
        sqlcommand.cpp

resources.files = main.qml
resources.prefix = /$${TARGET}
RESOURCES += \
    QML_Files.qrc \
    cPlusPlus.qrc \
    images.qrc \
    resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES    += \
<<<<<<< HEAD
    Assingment.qml \
    AssingmentModel.qml \
=======
    Resources/Images/E3S11.pdf \
    Resources/Images/Logo.png \
    Resources/Images/LogoDesign.png \
>>>>>>> 24aef10b67ede9216e9718c03907a5a8b78cba95
    Resources/Images/TestCopy.png \
    Resources/Images/homepage.png \
    Settings.qml \
    main.qml

HEADERS += \
    backend.h \
    sqlcommand.h
