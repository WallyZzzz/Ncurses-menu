#include "cmenupage.h"


int CMenuPage::m_intMenuX = 12;
int CMenuPage::m_intMenuY = 2;


CMenuPage::CMenuPage()
{

}

void CMenuPage::initMenu(int width, int height)
{
    m_intWidgetNumber = 0;
    m_intMenuNumber = 0;

    m_intWidth = width;
    m_intHeight = height;
    m_intStartX = (COLS - m_intWidth)/2;
    m_intStartY = (LINES - m_intHeight)/2;

    myWin = newwin(m_intHeight,m_intWidth,m_intStartY,m_intStartX);

    m_intCurrentY = m_intMenuY + 1;
}

void CMenuPage::setCurrentY(void)
{
    mvwaddch(myWin,m_intCurrentY,m_intMenuX - 1,'#');
}

void CMenuPage::show(void)
{
    werase(myWin);

    wborder(myWin,'|','|','-','-','*','*','*','*');
    showMenu();
    showWidget();
    setCurrentY();

    wrefresh(myWin);
}

void CMenuPage::clear(void)
{
    werase(myWin);
    wrefresh(myWin);
}

void CMenuPage::showMenu(void)
{
    for(int i = 1; i <= m_sMenuName.size(); i++)
    {
        mvwprintw(myWin, 1*i + m_intMenuY, 1 + m_intMenuX, m_sMenuName.at(i-1).toLocal8Bit());
    }
}

void CMenuPage::showWidget(void)
{
    updateMenuWidget();

    for(int i = 1; i<= m_sMenuWidget.size(); i++)
    {
        mvwprintw(myWin, 1*i + m_intMenuY, 20 + m_intMenuX, m_sMenuWidget.at(i-1).toLocal8Bit());
    }
}

void CMenuPage::setMenuName(const QStringList &menuName)
{
    m_sMenuName = menuName;

}

void CMenuPage::setMenuWidget(const QStringList &menuWidget)
{
    m_sMenuWidget = menuWidget;
}

void CMenuPage::bindNewWidget(const int &widgetLocal, CWidget *widgetName)
{
    m_widgetMask.insert(m_intWidgetNumber, widgetLocal);
    m_widgetName.insert(m_intWidgetNumber, widgetName);
    ++m_intWidgetNumber;
}

void CMenuPage::bindNewMenu(const int &menuMask, const int &menuLink)
{
    m_intMenuMask.insert(m_intMenuNumber, menuMask);
    m_intMenuLink.insert(m_intMenuNumber, menuLink);
    ++m_intMenuNumber;
}

QString CMenuPage::searchIndexInMenuWidget(void)
{

}

void CMenuPage::updateMenuWidget(void)
{
    int index = 0;
    for(int i = 0; i<m_intWidgetNumber; i++)
    {
        index = m_widgetMask.at(i);
        m_sMenuWidget.replace(index - 1, m_widgetName.at(i)->getText());
    }
}

bool CMenuPage::isOverMenu(void)
{
    if((m_intCurrentY > m_intMenuY + m_sMenuName.size()) || (m_intCurrentY < m_intMenuY+1))
        return TRUE;
    else
        return FALSE;
}

int CMenuPage::isNewMenu(void)
{
    int index = m_intMenuMask.indexOf(m_intCurrentY - m_intMenuY);
    if(index >= 0)
        return m_intMenuLink.at(index);
    else
        return -1;
}

void CMenuPage::downMove(void)
{
    ++m_intCurrentY;
    if(isOverMenu())
    {
        --m_intCurrentY;
    }
    else
    {
        mvwaddch(myWin, m_intCurrentY, m_intMenuX-1, '#');
        mvwaddch(myWin, m_intCurrentY-1, m_intMenuX-1, ' ');
        wrefresh(myWin);
    }
}

void CMenuPage::upMove(void)
{
    --m_intCurrentY;
    if(isOverMenu())
    {
        ++m_intCurrentY;
    }
    else
    {
        mvwaddch(myWin, m_intCurrentY, m_intMenuX-1, '#');
        mvwaddch(myWin, m_intCurrentY+1, m_intMenuX-1, ' ');
        wrefresh(myWin);
    }
}

void CMenuPage::rightMove(void)
{
    int index = m_widgetMask.indexOf(m_intCurrentY - m_intMenuY);
    if(index >= 0)
        m_widgetName.at(index)->rightAction();

    show();
}

void CMenuPage::leftMove(void)
{
    int index = m_widgetMask.indexOf(m_intCurrentY - m_intMenuY);
    if(index >= 0)
        m_widgetName.at(index)->leftAction();

    show();
}
