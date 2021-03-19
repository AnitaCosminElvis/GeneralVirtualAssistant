#ifndef GENERALTEXTTOSPEECHWRAPPER_H
#define GENERALTEXTTOSPEECHWRAPPER_H

#include "ITextToSpeech.h"
#include <QTextToSpeech>
#include <QThread>
#include <memory>

class TextToSpeechWrapper: public ITextToSpeech
{
public:
    TextToSpeechWrapper();

    int Initialize() override;
    void ConvertTextToSpeech(const std::string&) override;
    bool Stop() override;

private:
    std::unique_ptr<QTextToSpeech>  m_pSpeech;

};

#endif // GENERALTEXTTOSPEECHWRAPPER_H
