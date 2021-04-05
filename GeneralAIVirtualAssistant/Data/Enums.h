#ifndef ENUMS_H
#define ENUMS_H

enum class E_VA_TYPE: int
{
     UNDEFINED = -1,
     LOCAL = 0,
     WEB,
};

enum class E_COMMAND_INVOKER_TYPE
{
    UNDEFINED = -1,
    LOCAL_DEFAULT = 1,
    LOCAL_CUSTOM,
    WEB_DEFAULT,
    WEB_CUSTOM
};

enum class E_LOCAL_COMMAND_TYPE: int
{
    UNDEFINED = -1,
    CUSTOM = 0,
    START_APP,
    OPEN_DOC,
    PLAY_AUD,
    PLAY_VID,
    VIEW_PIC,
    COUNT
};

enum class E_WEB_COMMAND_TYPE: int
{
    UNDEFINED = -1,
    CUSTOM = 0,
    FIND_WIKI,
    DUCK_DUCK_GO,
    COUNT
};

union U_COMMAND_TYPE
{
    E_LOCAL_COMMAND_TYPE    localCmdType;
    E_WEB_COMMAND_TYPE      webCmdType;
    int                     nVal;
};

#endif // ENUMS_H
