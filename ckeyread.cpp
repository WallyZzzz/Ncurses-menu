#include "ckeyread.h"

CKeyRead::CKeyRead() : m_strUpKey('k'),
    m_strDownKey('j'),
    m_strLeftKey('h'),
    m_strRightKey('l'),
    m_strQuitKey('q'),
    m_strEnterKey('n'),
    m_strReadKey(' ')
{

}

void CKeyRead::initKeyRead(void)
{

}

void CKeyRead::getKey(void)
{
    m_strReadKey = getchar();
}

void CKeyRead::sendKey(void)
{

}

bool CKeyRead::isUp(void)
{
    if(m_strReadKey == m_strUpKey)
        return TRUE;
    else
        return FALSE;
}

bool CKeyRead::isDown(void)
{
    if(m_strReadKey == m_strDownKey)
        return TRUE;
    else
        return FALSE;
}

bool CKeyRead::isLeft(void)
{
    if(m_strReadKey == m_strLeftKey)
        return TRUE;
    else
        return FALSE;
}

bool CKeyRead::isRight(void)
{
    if(m_strReadKey == m_strRightKey)
        return TRUE;
    else
        return FALSE;
}

bool CKeyRead::isQuit(void)
{
    if(m_strReadKey == m_strQuitKey)
        return TRUE;
    else
        return FALSE;
}

bool CKeyRead::isEnter(void)
{
    if(m_strReadKey == m_strEnterKey)
        return TRUE;
    else
        return FALSE;
}
