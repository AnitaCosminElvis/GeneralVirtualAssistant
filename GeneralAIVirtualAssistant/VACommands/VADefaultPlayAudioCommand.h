#ifndef VADEFAULTPLAYMUSICCOMMAND_H
#define VADEFAULTPLAYMUSICCOMMAND_H

#define PLAY_COMMAND        "play"
#define RESOURCE_TYPE_AUD   "mus"
#define MIN_WORD_COUNT      2

#include "../Data/Enums.h"
#include "VAAbstractResourceFileCommand.h"

class VADefaultPlayAudioCommand: public VAAbstractResourceFileCommand
{
public:
    VADefaultPlayAudioCommand();

    int Initialize(const std::string& = "") override;
};

#endif // VADEFAULTPLAYMUSICCOMMAND_H
