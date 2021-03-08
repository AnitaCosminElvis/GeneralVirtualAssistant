#ifndef IVIRTUALASSISTANT_H
#define IVIRTUALASSISTANT_H

#include <string>

class IVirtualAssistant
{
public:
    virtual bool Initialize() = 0;
    virtual std::string GetResponse(std::string&, bool isRecording = true) = 0;
};

#endif // IVIRTUALASSISTANT_H
