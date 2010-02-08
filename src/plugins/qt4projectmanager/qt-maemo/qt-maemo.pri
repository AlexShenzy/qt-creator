SUPPORT_QT_MAEMO = $$(QTCREATOR_WITH_MAEMO)
!isEmpty(SUPPORT_QT_MAEMO) {
    message("Adding experimental support for Qt/Maemo applications.")
    DEFINES += QTCREATOR_WITH_MAEMO
    INCLUDEPATH += $$PWD/../../../libs/3rdparty/net7ssh/src
    INCLUDEPATH += $$PWD/../../../libs/3rdparty/botan/build
    LIBS += -l$$qtLibraryTarget(Net7ssh) -l$$qtLibraryTarget(Botan)
    HEADERS += $$PWD/maemorunconfiguration.h \
        $$PWD/maemomanager.h \
        $$PWD/maemotoolchain.h \
        $$PWD/maemodeviceconfigurations.h \
        $$PWD/maemosettingspage.h \
        $$PWD/maemosettingswidget.h \
        $$PWD/maemosshconnection.h \
        $$PWD/maemosshthread.h \
        $$PWD/maemoruncontrol.h \
        $$PWD/maemorunconfigurationwidget.h
    SOURCES += $$PWD/maemorunconfiguration.cpp \
        $$PWD/maemomanager.cpp \
        $$PWD/maemotoolchain.cpp \
        $$PWD/maemodeviceconfigurations.cpp \
        $$PWD/maemosettingspage.cpp \
        $$PWD/maemosettingswidget.cpp \
        $$PWD/maemosshconnection.cpp \
        $$PWD/maemosshthread.cpp \
        $$PWD/maemoruncontrol.cpp \
        $$PWD/maemorunconfigurationwidget.cpp
    FORMS += $$PWD/maemosettingswidget.ui
    RESOURCES += $$PWD/qt-maemo.qrc
}
