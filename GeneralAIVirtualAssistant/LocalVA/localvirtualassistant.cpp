#include "localvirtualassistant.h"
#include "SpeechTextIO/TextToSpeechWrapper.h"
#include "SpeechTextIO/SpeechToTextWrapper.h"
#include "../VACommands/VACommandsFactory.h"

LocalVirtualAssistant::LocalVirtualAssistant()
{
    m_pAimlParser.reset(new AIMLParser);
    m_pTextToSpeech.reset(new TextToSpeechWrapper);
    m_pSpeechToText.reset(new SpeechToTextWrapper);
    m_pCommandInvoker.reset(new CommandInvoker);
}

LocalVirtualAssistant::~LocalVirtualAssistant()
{
        m_pAimlParser->clear();
}

bool LocalVirtualAssistant::Initialize()
{
    QString qsDirPath = AIML_DIRECTORY;//+ QString("/") + qsAgeDirectory;

    if (false == m_pAimlParser->loadAIMLSet(qsDirPath))
    {
        return false;
    }

    m_pTextToSpeech->Initialize();
    m_pSpeechToText->Initialize();
    m_pCommandInvoker->Initialize();

    return true;
}

std::string LocalVirtualAssistant::GetResponse(std::string &input, bool isRecording)
{
    if (isRecording){
        input = m_pSpeechToText->ConvertSpeechToText();
    }

    std::string response = GetResponeFromInput(input);

    m_pTextToSpeech->ConvertTextToSpeech(response);

    return response;
}

std::string LocalVirtualAssistant::GetResponeFromInput(std::string &input)
{
    std::string response;

    if (!input.empty())
    {
        if (input.rfind("stop",0) == 0)
        {
            if (m_pCommandInvoker->StopCommand(m_lastCmdType)) response = VA_CMD_SUCCESS;
            else response  =VA_CMD_PARTIAL;

            m_pTextToSpeech->Stop();
        }
        else if (m_lastCmdType = m_pCommandInvoker->IsCommand(input); m_lastCmdType != E_COMMAND_TYPE::UNDEFINED)
        {
            (m_pCommandInvoker->ExecuteCommand(input,m_lastCmdType))? (response = VA_CMD_SUCCESS) : (response = VA_CMD_FAIL);
            std::list<std::string> list = m_pCommandInvoker->GetResult(m_lastCmdType);
            response += list.front();
        }else{
            response = m_pAimlParser->getResponse(input.data()).toLocal8Bit().data();
        }
    }

    if (response.empty()) response = VA_SORRY;

    return response;
}
