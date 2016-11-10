#ifndef CKEYREAD_H
#define CKEYREAD_H
#include "ncurses.h"


class CKeyRead
{
public:
    CKeyRead();
    void initKeyRead(void);
    void getKey(void);
    void sendKey(void);
    bool isUp(void);
    bool isDown(void);
    bool isLeft(void);
    bool isRight(void);
    bool isQuit(void);
    bool isEnter(void);

private:
    char m_strUpKey;
    char m_strDownKey;
    char m_strLeftKey;
    char m_strRightKey;
    char m_strQuitKey;
    char m_strEnterKey;
    char m_strReadKey;
};

#endif // CKEYREAD_H
