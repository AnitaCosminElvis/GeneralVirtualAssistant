#ifndef VADEFAULTPLAYVIDEOCOMMAND_H
#define VADEFAULTPLAYVIDEOCOMMAND_H


#define PLAY_COMMAND    "play"
#define RESOURCE_TYPE   "vid"
#define MIN_WORD_COUNT  3

#include "../Data/Enums.h"
#include "VAAbstractResourceFileCommand.h"

class VADefaultPlayVideoCommand: public VAAbstractResourceFileCommand
{
public:
    VADefaultPlayVideoCommand();

    int Initialize() override;
};

#endif // VADEFAULTPLAYVIDEOCOMMAND_H
