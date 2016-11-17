#include "ckeyread.h"

CKeyRead::CKeyRead()
{

}

void CKeyRead::getKey(WINDOW *win)
{
    keypad(win, TRUE);
    m_intReadKey = wgetch(win);
}

char CKeyRead::readKey(void)
{
    switch(m_intReadKey)
    {
    case KEY_UP:
    case 'k':return keyUp;

    case KEY_DOWN:
    case 'j':return keyDown;

    case KEY_LEFT:
    case 'h':return keyLeft;

    case KEY_RIGHT:
    case 'l':return keyRight;

    case 10:
    case 'n':return keyEnter;

    case 27:                         //27 = esc
    case 'q':return keyQuit;

    default:return -1;
    }
}



