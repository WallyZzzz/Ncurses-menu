#include "cmenuctrl.h"

CMenuCtrl::CMenuCtrl()
{

}

void CMenuCtrl::initMenuCtrl(void)
{

}

void CMenuCtrl::setHomePage(CMenuPage *newMenu)
{
    m_pMenuPage = newMenu;
}

void CMenuCtrl::moveUp(void)
{
    m_pMenuPage->upMove();
}

void CMenuCtrl::moveDown(void)
{
    m_pMenuPage->downMove();
}

void CMenuCtrl::moveLeft(void)
{
    m_pMenuPage->leftMove();
}

void CMenuCtrl::moveRight(void)
{
    m_pMenuPage->rightMove();
}

void CMenuCtrl::enterMenu(void)
{
    CMenuPage *index = m_pMenuPage->enterMenu();
    if(index != NULL)
    {
        preMenu.push(m_pMenuPage);
        m_pMenuPage->clear();
        m_pMenuPage = index;

        show();
    }
}

void CMenuCtrl::show(void)
{
    m_pMenuPage->show();
}

void CMenuCtrl::quitMenu(void)
{
    m_pMenuPage = preMenu.top();
    preMenu.pop();
    show();
}
