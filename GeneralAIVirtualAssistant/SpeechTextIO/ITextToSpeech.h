#ifndef ITEXTTOSPEECH_H
#define ITEXTTOSPEECH_H

#include <string>

class ITextToSpeech {
public:
    virtual int Initialize() = 0;
    virtual void ConvertTextToSpeech(const std::string&) = 0;
};

#endif // ITEXTTOSPEECH_H
