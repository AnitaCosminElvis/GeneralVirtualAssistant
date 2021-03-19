#ifndef ENUMS_H
#define ENUMS_H

enum class E_VA_TYPE: int
{
     LOCAL = 0,
     WEB,
};

enum class E_COMMAND_TYPE: int
{
    UNDEFINED = -1,
    CUSTOM = 0,
    START_APP,
    OPEN_DOC,
    PLAY_AUD,
    PLAY_VID,
    VIEW_PIC,
    FIND_WIKI,
    COUNT
};

union U_COMMAND_TYPE
{
    E_COMMAND_TYPE  command_type;
    int             nVal;
};

#endif // ENUMS_H
