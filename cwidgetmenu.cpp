#include "cwidgetmenu.h"

CWidgetMenu::CWidgetMenu(const string menuName, CMenuPage *nextMenu)
{
    m_sMenuName = menuName;
    m_pNextMenu = nextMenu;
}

CMenuPage *CWidgetMenu::isNewMenu(void)
{
    return m_pNextMenu;
}

string CWidgetMenu::getText(void)
{
    return m_sMenuName + ">>";
}

void CWidgetMenu::leftAction(void)
{

}

void CWidgetMenu::rightAction(void)
{

}
