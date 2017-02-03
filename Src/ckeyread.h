#ifndef CKEYREAD_H
#define CKEYREAD_H
#include <curses.h>
#include "cmenuctrl.h"
#include <QDebug>

#define keyUp 0x01
#define keyDown 0x02
#define keyLeft 0x03
#define keyRight 0x04
#define keyEnter 0x05
#define keyQuit 0x06

class CKeyRead
{
public:
    CKeyRead();
    void getKey(WINDOW *win);
    char readKey(void);
private:
    int m_intReadKey;
};

#endif // CKEYREAD_H
