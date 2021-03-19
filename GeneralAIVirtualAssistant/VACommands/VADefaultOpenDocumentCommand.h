#ifndef VADEFAULTOPENFILECOMMAND_H
#define VADEFAULTOPENFILECOMMAND_H

#define OPEN_COMMAND   "open"
#define RESOURCE_TYPE   "doc"
#define MIN_WORD_COUNT  3

#include <QString>
#include <QStringList>

#include "VAAbstractResourceFileCommand.h"

class VADefaultOpenDocumentCommand: public VAAbstractResourceFileCommand
{
public:
    VADefaultOpenDocumentCommand();

    int Initialize() override;
};

#endif // VADEFAULTOPENFILECOMMAND_H
