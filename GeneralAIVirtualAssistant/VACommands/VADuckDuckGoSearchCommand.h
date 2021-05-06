#ifndef VAGOOGLESEARCHCOMMAND_H
#define VAGOOGLESEARCHCOMMAND_H

#include "VAWebAbstractCommand.h"
#include "VAWebWikiSearchCommand.h"

#include <QRegularExpression>

class VADuckDuckGoSearchCommand: public VAWebAbstractCommand
{
public:
    VADuckDuckGoSearchCommand();

    int     Initialize(const std::string& = "") override;
    bool    ContainsCommand(const std::string& input) override;
    bool    ExecuteCommand(const std::string& input) override;
    bool    StopCommand() override;

private:
    QString                             m_qsParams;
    QRegularExpression                  m_hrefRegExp;
    VAWebWikiSearchCommand              m_wikiApi;
};

#endif // VAGOOGLESEARCHCOMMAND_H
