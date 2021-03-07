#ifndef ISPEECHTOTEXTIO_H
#define ISPEECHTOTEXTIO_H

#include <string>

class ISpeechToText {
public:
    virtual int Initialize() = 0;
    virtual std::string ConvertSpeechToText(const void*) = 0;
};

#endif // ISPEECHTOTEXTIO_H
