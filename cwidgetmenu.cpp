#include "cwidgetmenu.h"

CWidgetMenu::CWidgetMenu()
{

}

void CWidgetMenu::initWidget(const string menuName, const string menuWidget, CMenuPage *nextMenu)
{
    m_sMenuName = menuName;
    m_pNextMenu = nextMenu;
}

bool CWidgetMenu::isNewMenu(void)
{
    return TRUE;
}
