#ifndef VADEFAULTOPENFILECOMMAND_H
#define VADEFAULTOPENFILECOMMAND_H

#define OPEN_COMMAND        "open"
#define RESOURCE_TYPE_DOC   "doc"
#define MIN_WORD_COUNT      2

#include <QString>
#include <QStringList>

#include "VAAbstractResourceFileCommand.h"

class VADefaultOpenDocumentCommand: public VAAbstractResourceFileCommand
{
public:
    VADefaultOpenDocumentCommand();

    int Initialize(const std::string& = "") override;
};

#endif // VADEFAULTOPENFILECOMMAND_H
