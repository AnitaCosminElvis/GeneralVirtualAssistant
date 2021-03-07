QT  -= gui
QT  += core xml network texttospeech

TEMPLATE = lib
DEFINES += GENERALAIVIRTUALASSISTANT_LIBRARY

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LocalVA/localvirtualassistant.cpp \
    SpeechTextIO/IBMWatsonSpeechToTextWrapper.cpp \
    SpeechTextIO/generaltexttospeechwrapper.cpp \
    SpeechTextIO/pocketsphynxspeechtotextwrapper.cpp \
    WebVA/webvirtualassistant.cpp \
    generalaivirtualassistant.cpp \
    LocalVA/aimlparser.cpp \
    virtualassistanfactorymethod.cpp

HEADERS += \
    Data/Defines.h \
    Data/Enums.h \
    GeneralAIVirtualAssistant_global.h \
    LocalVA/localvirtualassistant.h \
    SpeechTextIO/IBMWatsonSpeechToTextWrapper.h \
    SpeechTextIO/ISpeechToText.h \
    SpeechTextIO/ITextToSpeech.h \
    SpeechTextIO/generaltexttospeechwrapper.h \
    SpeechTextIO/pocketsphynxspeechtotextwrapper.h \
    WebVA/webvirtualassistant.h \
    generalaivirtualassistant.h \
    LocalVA/aimlparser.h \
    ivirtualassistant.h \
    virtualassistanfactorymethod.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/SpeechTextIO/bin/Release/x64 \
               $$PWD/SpeechTextIO/bin/include \
               $$PWD/SpeechTextIO/bin/include/sphinxbase \
               $$PWD/SpeechTextIO/bin/include/win32 \
               #$$PWD/SpeechTextIO/bin/include/wince \



