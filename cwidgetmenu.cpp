#include "cwidgetmenu.h"

CWidgetMenu::CWidgetMenu()
{

}

void CWidgetMenu::initWidget(const string menuName, const string menuWidget, CMenuPage *nextMenu)
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
