#include "TextToSpeechWrapper.h"

TextToSpeechWrapper::TextToSpeechWrapper()
{

}

int TextToSpeechWrapper::Initialize()
{
    return 1;
}

void TextToSpeechWrapper::ConvertTextToSpeech(const std::string &response)
{
    //convert text to QString
    QString qResponse(response.data());

    // Create an instance using the default engine/plugin.
    QTextToSpeech *speech = new QTextToSpeech();

    // Set locale.
    speech->setLocale(QLocale(QLocale::English, QLocale::LatinScript, QLocale::UnitedStates));
    // List the available voices.

    // Say something.
    speech->say(qResponse);

    // Wait for sound to play before exiting.
    QThread::sleep(1);
}
