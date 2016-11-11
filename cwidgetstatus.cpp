#include "cwidgetstatus.h"

CWidgetStatus::CWidgetStatus()
{

}

void CWidgetStatus::initWidget(const string menuName, const string menuWidget, CMenuPage *nextMenu)
{
    m_sMenuName = menuName;
    if(menuWidget == "true")
        m_boolStatus = true;
    else
        m_boolStatus = false;
}

void CWidgetStatus::leftAction(void)
{
    m_boolStatus = (m_boolStatus == true)?false:true;
}

void CWidgetStatus::rightAction(void)
{
    m_boolStatus = (m_boolStatus == true)?false:true;
}

string CWidgetStatus::getText(void)
{
    if(m_boolStatus)
        return m_sMenuName + "TRUE";
    else
        return m_sMenuName + "FALSE";
}

CMenuPage *CWidgetStatus::isNewMenu(void)
{
    return NULL;
}
