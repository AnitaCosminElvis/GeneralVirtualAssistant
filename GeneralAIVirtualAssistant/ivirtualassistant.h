#ifndef IVIRTUALASSISTANT_H
#define IVIRTUALASSISTANT_H

#include <string>

class IVirtualAssistant
{
public:
    virtual bool Initialize() = 0;
    virtual std::string GetResponse(std::string&) = 0;
};

#endif // IVIRTUALASSISTANT_H
