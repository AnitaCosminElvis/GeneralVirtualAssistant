#ifndef VADEFAULTVIEWPICTURECOMMAND_H
#define VADEFAULTVIEWPICTURECOMMAND_H

#define VIEW_COMMAND        "view"
#define RESOURCE_TYPE_PIC   "pic"
#define MIN_WORD_COUNT      2

#include <QString>
#include <QStringList>

#include "VAAbstractResourceFileCommand.h"

class VADefaultViewPictureCommand: public VAAbstractResourceFileCommand
{
public:
    VADefaultViewPictureCommand();

    int Initialize(const std::string& = "") override;
};

#endif // VADEFAULTVIEWPICTURECOMMAND_H
