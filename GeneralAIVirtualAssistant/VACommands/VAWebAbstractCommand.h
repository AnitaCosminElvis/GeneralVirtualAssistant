#ifndef VAWEBABSTRACTCOMMAND_H
#define VAWEBABSTRACTCOMMAND_H

#include "IVACommand.h"
#include "../Data/Structs.h"
#include "../Utils/WebClient.h"

#include <memory>

class VAWebAbstractCommand: public IVACommand
{
public:
    VAWebAbstractCommand();
    virtual ~VAWebAbstractCommand() = default;

    int                     GetCommandType() override;
    int                     GetCommandID() override;
    std::string             GetCommandResult() override;

protected:
    std::unique_ptr<WebClient>          m_pWebClient;
    QString                             m_qsUrl;
    S_BASE_COMMAND_DATA                 m_BaseCmdData;
    std::string                         m_result;
};

#endif // VAWEBABSTRACTCOMMAND_H
