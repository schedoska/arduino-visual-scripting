QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Panels_data/comparatorpaneldata.cpp \
    Panels_data/indexmanager.cpp \
    Panels_data/pinoutputpaneldata.cpp \
    connectionline.cpp \
    customviewport.cpp \
    flowchartscene.cpp \
    gainpanel.cpp \
    loadmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    mathcompraratorpanel.cpp \
    muxpnael.cpp \
    node.cpp \
    panel.cpp \
    panelmenu.cpp \
    panelstyle.cpp \
    pininputpanel.cpp \
    pinoutpanelpinselector.cpp \
    pinoutputpanel.cpp \
    savemanager.cpp \
    shadow.cpp

HEADERS += \
    Panels_data/comparatorpaneldata.h \
    Panels_data/indexmanager.h \
    Panels_data/pinoutputpaneldata.h \
    connectionline.h \
    customviewport.h \
    flowchartscene.h \
    gainpanel.h \
    loadmanager.h \
    mainwindow.h \
    mathcompraratorpanel.h \
    muxpnael.h \
    node.h \
    panel.h \
    panelmenu.h \
    panelstyle.h \
    pininputpanel.h \
    pinoutpanelpinselector.h \
    pinoutputpanel.h \
    savemanager.h \
    shadow.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Pulpit/chinese.msyh.ttf
