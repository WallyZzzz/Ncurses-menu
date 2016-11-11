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
    m_boolStatus = (m_myStatus == true)?false:true;
}

void CWidgetStatus::rightAction(void)
{
    m_boolStatus = (m_myStatus == true)?false:true;
}

string CWidgetStatus::getText(void)
{
    if(m_myStatus)
        return m_sMenuName + "TRUE";
    else
        return m_sMenuName + "FALSE";
}

bool CWidgetStatus::isNewMenu(void)
{
    return FALSE;
}
