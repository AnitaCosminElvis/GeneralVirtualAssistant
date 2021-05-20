#ifndef VADEFAULTPLAYVIDEOCOMMAND_H
#define VADEFAULTPLAYVIDEOCOMMAND_H


#define PLAY_COMMAND        "play"
#define RESOURCE_TYPE_VID   "vid"
#define MIN_WORD_COUNT      2

#include "../Data/Enums.h"
#include "VAAbstractResourceFileCommand.h"

class VADefaultPlayVideoCommand: public VAAbstractResourceFileCommand
{
public:
    VADefaultPlayVideoCommand();

    int Initialize(const std::string& = "") override;
};

#endif // VADEFAULTPLAYVIDEOCOMMAND_H
