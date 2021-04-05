QT  -= gui
QT  += core xml network texttospeech multimedia xmlpatterns

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
    InputFilter.cpp \
    LocalVA/localvirtualassistant.cpp \
    SpeechTextIO/IBMWatsonSpeechToText.cpp \
    SpeechTextIO/SpeechToTextWrapper.cpp \
    SpeechTextIO/TextToSpeechWrapper.cpp \
    SpeechTextIO/pocketsphynxspeechtotextwrapper.cpp \
    Utils/FileUtility.cpp \
    Utils/JSONHandler.cpp \
    Utils/ProcessUtility.cpp \
    Utils/WebClient.cpp \
    VACommands/InvokerFactoryCreator.cpp \
    VACommands/LocalCustomCommandInvoker.cpp \
    VACommands/LocalDefaultCommandInvoker.cpp \
    VACommands/LocalInvokerFactory.cpp \
    VACommands/VAAbstractCustomCommand.cpp \
    VACommands/VAAbstractResourceFileCommand.cpp \
    VACommands/VACommandsFactory.cpp \
    VACommands/VADefaultOpenDocumentCommand.cpp \
    VACommands/VADefaultPlayAudioCommand.cpp \
    VACommands/VADefaultPlayVideoCommand.cpp \
    VACommands/VADefaultStartAppCommand.cpp \
    VACommands/VADefaultViewPictureCommand.cpp \
    VACommands/VADuckDuckGoSearchCommand.cpp \
    VACommands/VALocalCustomCommand.cpp \
    VACommands/VAWebCustomCommand.cpp \
    VACommands/VAWebWikiSearchCommand.cpp \
    VACommands/WebCustomCommandInvoker.cpp \
    VACommands/WebDefaultCommandInvoker.cpp \
    VACommands/WebInvokerFactory.cpp \
    WebVA/webvirtualassistant.cpp \
    SpeechTextIO/audiorecorder.cpp \
    generalaivirtualassistant.cpp \
    LocalVA/aimlparser.cpp \
    virtualassistanfactorymethod.cpp

HEADERS += \
    Data/Defines.h \
    Data/Enums.h \
    Data/Structs.h \
    GeneralAIVirtualAssistant_global.h \
    InputFilter.h \
    LocalVA/localvirtualassistant.h \
    SpeechTextIO/IBMWatsonSpeechToText.h \
    SpeechTextIO/ISpeechToText.h \
    SpeechTextIO/ITextToSpeech.h \
    SpeechTextIO/SpeechToTextWrapper.h \
    SpeechTextIO/TextToSpeechWrapper.h \
    SpeechTextIO/pocketsphynxspeechtotextwrapper.h \
    Utils/FileUtility.h \
    Utils/JSONHandler.h \
    Utils/ProcessUtility.h \
    Utils/WebClient.h \
    VACommands/ICommandInvoker.h \
    VACommands/ICommandInvokerFactory.h \
    VACommands/IVACommand.h \
    VACommands/InvokerFactoryCreator.h \
    VACommands/LocalCustomCommandInvoker.h \
    VACommands/LocalDefaultCommandInvoker.h \
    VACommands/LocalInvokerFactory.h \
    VACommands/VAAbstractCustomCommand.h \
    VACommands/VAAbstractResourceFileCommand.h \
    VACommands/VACommandsFactory.h \
    VACommands/VADefaultOpenDocumentCommand.h \
    VACommands/VADefaultPlayAudioCommand.h \
    VACommands/VADefaultPlayVideoCommand.h \
    VACommands/VADefaultStartAppCommand.h \
    VACommands/VADefaultViewPictureCommand.h \
    VACommands/VADuckDuckGoSearchCommand.h \
    VACommands/VALocalCustomCommand.h \
    VACommands/VAWebCustomCommand.h \
    VACommands/VAWebWikiSearchCommand.h \
    VACommands/WebCustomCommandInvoker.h \
    VACommands/WebDefaultCommandInvoker.h \
    VACommands/WebInvokerFactory.h \
    WebVA/webvirtualassistant.h \
    SpeechTextIO/audiorecorder.h \
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



