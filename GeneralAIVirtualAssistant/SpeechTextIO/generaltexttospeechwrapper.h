#ifndef GENERALTEXTTOSPEECHWRAPPER_H
#define GENERALTEXTTOSPEECHWRAPPER_H

#include "ITextToSpeech.h"
#include <QTextToSpeech>
#include <QThread>

class GeneralTextToSpeechWrapper: public ITextToSpeech
{
public:
    GeneralTextToSpeechWrapper();
    void ConvertTextToSpeech(const std::string&) override;
};

#endif // GENERALTEXTTOSPEECHWRAPPER_H
