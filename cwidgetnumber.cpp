#include "cwidgetnumber.h"

CWidgetNumber::CWidgetNumber()
{

}

void CWidgetNumber::initWidget(const string menuName, const string menuWidget, CMenuPage *nextMenu)
{
    m_sMenuName = menuName;
    m_intNumber = atoi(menuWidget.c_str());
}

void CWidgetNumber::leftAction(void)
{
    if(!--m_intNumber)
        ++m_intNumber;
}

void CWidgetNumber::rightAction(void)
{
    if(++m_intNumber > 100)
        --m_intNumber;
}

string CWidgetNumber::getText(void)
{
    stringstream ss;
    string result;

    ss << m_intNumber;
    ss >> result;

    return m_sMenuName + result;
}

CMenuPage *CWidgetNumber::isNewMenu(void)
{
    return NULL;
}

