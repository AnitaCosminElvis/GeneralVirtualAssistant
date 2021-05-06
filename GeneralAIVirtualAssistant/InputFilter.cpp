#include "InputFilter.h"
#include "Utils/JSONHandler.h"
#include "Data/Defines.h"

#include <QDir>

bool InputFilter::Initialize()
{
    QString path = QDir::currentPath() + DATA_PATH + SAFE_LIST_PATH;
    JSONHandler jsonHandler;

    if (jsonHandler.LoadJSONFromSettingsFile(path)){
        if ("false" == jsonHandler.GetValueByJSONPath({"isDenyListType"})) m_isDenyList = false;

        m_strings = jsonHandler.GetArrayValuesByJSONPath({"strings"});

        m_urls = jsonHandler.GetArrayValuesByJSONPath({"urls"});
    }

    return true;
}

bool InputFilter::CanContinue(QString input)
{
    //set a default blacklist check
    bool canContinue  = false;

    //set a whitelist check if it's not a deny list type
    if (!m_isDenyList) canContinue  = true;

    for (auto element: m_strings){
        if ((element.contains(input, Qt::CaseInsensitive)) || (input.contains(element, Qt::CaseInsensitive)))
            return canContinue;
    }

    for (auto element: m_urls){
        if ((element.contains(input, Qt::CaseInsensitive)) || (input.contains(element, Qt::CaseInsensitive)))
            return canContinue;
    }

    return (m_isDenyList)? true: false;
}
