#ifndef ITEXTTOSPEECH_H
#define ITEXTTOSPEECH_H

#include <string>

class ITextToSpeech {
public:
    virtual void ConvertTextToSpeech(const std::string&) = 0;
};

#endif // ITEXTTOSPEECH_H
