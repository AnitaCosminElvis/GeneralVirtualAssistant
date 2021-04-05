#ifndef VAWEBCUSTOMCOMMAND_H
#define VAWEBCUSTOMCOMMAND_H

#include "VAAbstractCustomCommand.h"

#include <QString>

class VAWebCustomCommand : public VAAbstractCustomCommand
{
public:
    VAWebCustomCommand();

    int GetCommandType() override;
};

#endif // VAWEBCUSTOMCOMMAND_H
