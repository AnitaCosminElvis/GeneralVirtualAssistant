#ifndef VADEFAULTVIEWPICTURECOMMAND_H
#define VADEFAULTVIEWPICTURECOMMAND_H

#define VIEW_COMMAND    "view"
#define RESOURCE_TYPE   "pic"
#define MIN_WORD_COUNT  3

#include <QString>
#include <QStringList>

#include "VAAbstractResourceFileCommand.h"

class VADefaultViewPictureCommand: public VAAbstractResourceFileCommand
{
public:
    VADefaultViewPictureCommand();

    int Initialize() override;
};

#endif // VADEFAULTVIEWPICTURECOMMAND_H
