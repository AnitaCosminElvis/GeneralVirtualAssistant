#ifndef PROCESSUTILITY_H
#define PROCESSUTILITY_H

#include <QString>

class ProcessUtility
{
public:
    static bool StartApplicationByPath(QString qsAppPath);
    static bool StartApplication(QString qsApp);
    static bool OpenFileByPath(QString qsFilePath);
};

#endif // PROCESSUTILITY_H
