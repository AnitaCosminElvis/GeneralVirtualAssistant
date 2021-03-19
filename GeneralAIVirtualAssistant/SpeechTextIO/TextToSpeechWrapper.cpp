#include "TextToSpeechWrapper.h"

TextToSpeechWrapper::TextToSpeechWrapper()
{
    // Create an instance using the default engine/plugin.
    m_pSpeech.reset(new QTextToSpeech());
}

int TextToSpeechWrapper::Initialize()
{
    // Set locale.
    m_pSpeech->setLocale(QLocale(QLocale::English, QLocale::LatinScript, QLocale::UnitedStates));
    return 1;
}

void TextToSpeechWrapper::ConvertTextToSpeech(const std::string &response)
{

    //convert text to QString
    QString qResponse(response.data());

    Stop();

    // Say something.
    m_pSpeech->say(qResponse);

    // Wait for sound to play before exiting.
    QThread::sleep(1);
}

bool TextToSpeechWrapper::Stop()
{
    if (QTextToSpeech::State::Ready != m_pSpeech->state()) m_pSpeech->stop();

    return true;
}
