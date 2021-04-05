#ifndef VAABSTRACTCOMMAND_H
#define VAABSTRACTCOMMAND_H

#include "IVACommand.h"
#include "../Data/Structs.h"

#include <QString>
#include <QStandardPaths>

class VAAbstractResourceFileCommand: public IVACommand
{
public:
    VAAbstractResourceFileCommand();
    virtual ~VAAbstractResourceFileCommand() = default;

    bool ContainsCommand(const std::string &input) override;
    bool ExecuteCommand(const std::string &input) override;
    bool StopCommand() override;
    int GetCommandType() override;
    int GetCommandID() override;
    std::string GetCommandResult() override;

protected:
    QStandardPaths::StandardLocation    m_StdLocation;
    S_BASE_COMMAND_DATA                 m_BaseCmdData;
    std::string                         m_result;
};

#endif // VAABSTRACTCOMMAND_H
