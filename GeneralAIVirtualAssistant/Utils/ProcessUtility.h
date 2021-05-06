#ifndef PROCESSUTILITY_H
#define PROCESSUTILITY_H

#include <QString>

class ProcessUtility
{
public:
    static bool StartApplicationByPath(QString qsAppPath);
    static bool StartApplication(QString qsApp);
};

#endif // PROCESSUTILITY_H
