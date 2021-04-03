#ifndef INPUTFILTER_H
#define INPUTFILTER_H

#include <QStringList>

class InputFilter
{
public:
    InputFilter();

    bool Initialize();
    bool CanContinue(QString input);

private:
    bool        m_isDenyList    = true;
    QStringList m_strings;
    QStringList m_urls;
};

#endif // INPUTFILTER_H
