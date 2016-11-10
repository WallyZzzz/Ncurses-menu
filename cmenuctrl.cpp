#include "cmenuctrl.h"

CMenuCtrl::CMenuCtrl() : m_intCurrentMenu(0),m_intMenuPageNum(0)
{

}

void CMenuCtrl::initMenuCtrl(void)
{

}

void CMenuCtrl::addMenuPage(CMenuPage *newMenu)
{
    m_myMenuP.insert(m_myMenuP.end(),newMenu);
    ++m_intMenuPageNum;
}

void CMenuCtrl::moveUp(void)
{
    m_myMenuP.at(m_intCurrentMenu)->upMove();
}

void CMenuCtrl::moveDown(void)
{
    m_myMenuP.at(m_intCurrentMenu)->downMove();
}

void CMenuCtrl::moveLeft(void)
{
    m_myMenuP.at(m_intCurrentMenu)->leftMove();
}

void CMenuCtrl::moveRight(void)
{
    m_myMenuP.at(m_intCurrentMenu)->rightMove();
}

void CMenuCtrl::enterMenu(void)
{
    int index = m_myMenuP.at(m_intCurrentMenu)->isNewMenu();
    if(index >= 0)
    {
        preMenu.push(m_myMenuP.at(m_intCurrentMenu));
        m_myMenuP.at(m_intCurrentMenu)->clear();
        m_intCurrentMenu = index;

        show();
    }
}

void CMenuCtrl::show(void)
{
    m_myMenuP.at(m_intCurrentMenu)->show();
}

void CMenuCtrl::quitMenu(void)
{
    vector<CMenuPage*>::iterator index = find(m_myMenuP.begin(), m_myMenuP.end(), preMenu.top());
    preMenu.pop();
    if(index - m_myMenuP.begin() >= 0)
    {
        m_intCurrentMenu = index - m_myMenuP.begin();

        show();
    }
}
