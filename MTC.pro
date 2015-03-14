QT += core gui sql network

DEFINES += WINVER=0x0501
LIBS += -lrasapi32

CONFIG += qt warn_on

TARGET = MTC
TEMPLATE = app

RC_FILE = resource/mtc.rc

RESOURCES += resource/images.qrc \
    resource/languages.qrc

TRANSLATIONS = resource/MTC_ru_RU.ts \
    resource/MTC_uk_UA.ts \
    resource/MTC_en_US.ts

SOURCES += main.cpp\
    MainWindow.cpp \
    ImageButton.cpp \
    SingleApplication.cpp \
    AnimateButton.cpp \
    DeamonDatabase.cpp \
    DeamonPort.cpp \
    DeamonNetwork.cpp \
    DeamonConnection.cpp \
    At.cpp \
    ExitDialog.cpp \
    HomeWidget.cpp \
    ProfileWidget.cpp \
    SafetyWidget.cpp \
    SystemWidget.cpp \
    HelpWidget.cpp \
    LanguageWidget.cpp \
    DeamonSetting.cpp \
    SettingWidget.cpp \
    TimeLabel.cpp

HEADERS  += MainWindow.h \
    ImageButton.h \
    SingleApplication.h \
    AnimateButton.h \
    DeamonDatabase.h \
    DeamonPort.h \
    DeamonNetwork.h \
    DeamonConnection.h \
    At.h \
    Define.h \
    DeamonSetting.h \
    ExitDialog.h \
    HomeWidget.h \
    ProfileWidget.h \
    SafetyWidget.h \
    SystemWidget.h \
    HelpWidget.h \
    LanguageWidget.h \
    SettingWidget.h \
    TimeLabel.h

HEADERS += SerialPort.h \
        SerialEnumerator.h \

SOURCES	+= SerialPort.cpp

unix:SOURCES += SerialPortPosix.cpp
unix:!macx:SOURCES += SerialPortUnix.cpp

macx {
  SOURCES          += SerialPortOsx.cpp
  LIBS             += -framework IOKit -framework CoreFoundation
}

win32 {
  SOURCES          += SerialPortWin.cpp SerialEnumeratorWin.cpp
  LIBS             += -lsetupapi -ladvapi32 -luser32
}




















