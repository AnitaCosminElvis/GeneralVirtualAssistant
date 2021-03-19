#ifndef VADEFAULTPLAYMUSICCOMMAND_H
#define VADEFAULTPLAYMUSICCOMMAND_H

#define PLAY_COMMAND   "play"
#define RESOURCE_TYPE   "aud"
#define MIN_WORD_COUNT  3

#include "../Data/Enums.h"
#include "VAAbstractResourceFileCommand.h"

class VADefaultPlayAudioCommand: public VAAbstractResourceFileCommand
{
public:
    VADefaultPlayAudioCommand();

    int Initialize() override;
};

#endif // VADEFAULTPLAYMUSICCOMMAND_H
