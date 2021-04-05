#ifndef VACUSTOMCOMMAND_H
#define VACUSTOMCOMMAND_H

#include "IVACommand.h"
#include "../Data/Structs.h"

#include <QString>
#include <QStandardPaths>
#include <QLibrary>
#include <memory>

class VAAbstractCustomCommand: public IVACommand
{
public:
    VAAbstractCustomCommand();
    virtual ~VAAbstractCustomCommand();

    int Initialize(const std::string& filename = "") override;
    bool ContainsCommand(const std::string &input) override;
    bool ExecuteCommand(const std::string &input) override;
    bool StopCommand() override;
    int GetCommandID() override;
    std::string GetCommandResult() override;

protected:
    std::unique_ptr<QLibrary>           m_CmdLib;
    S_CUSTOM_CMD_LIB_DATA               m_LibData;
    E_VA_TYPE                           m_VAType;
    int                                 m_cmdID;
};

#endif // VACUSTOMCOMMAND_H
