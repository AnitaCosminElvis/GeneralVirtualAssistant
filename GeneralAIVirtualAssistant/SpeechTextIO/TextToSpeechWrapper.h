#ifndef GENERALTEXTTOSPEECHWRAPPER_H
#define GENERALTEXTTOSPEECHWRAPPER_H

#include "ITextToSpeech.h"
#include <QTextToSpeech>
#include <QThread>

class TextToSpeechWrapper: public ITextToSpeech
{
public:
    TextToSpeechWrapper();

    int Initialize() override;
    void ConvertTextToSpeech(const std::string&) override;
};

#endif // GENERALTEXTTOSPEECHWRAPPER_H
