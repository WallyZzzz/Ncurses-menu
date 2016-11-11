#include "cmenupage.h"


int CMenuPage::m_intMenuX = 12;
int CMenuPage::m_intMenuY = 2;


CMenuPage::CMenuPage()
{

}

void CMenuPage::initMenu(int width, int height)
{
    m_intWidth = width;
    m_intHeight = height;
    m_intStartX = (COLS - m_intWidth)/2;
    m_intStartY = (LINES - m_intHeight)/2;

    myWin = newwin(m_intHeight,m_intWidth,m_intStartY,m_intStartX);

    m_intCurrentY = m_intMenuY + 1;
}

void CMenuPage::bindNewWidget(CWidget *newWidget)
{
    m_vWidget.push_back(newWidget);
}

void CMenuPage::setCurrentY(void)
{
    mvwaddch(myWin,m_intCurrentY,m_intMenuX - 1,'#');
}

void CMenuPage::show(void)
{
    werase(myWin);
    wborder(myWin,'|','|','-','-','*','*','*','*');
    showWidget();
    setCurrentY();
    wrefresh(myWin);
}

void CMenuPage::clear(void)
{
    werase(myWin);
    wrefresh(myWin);
}

void CMenuPage::showWidget(void)
{
   vector<CWidget*>::iterator itWidget;
   for(itWidget = m_vWidget.begin(); itWidget != m_vWidget.end(); itWidget++)
       mvwprintw(myWin, m_intMenuY, m_intMenuX, *itWidget->getText());
}

bool CMenuPage::isOverMenu(void)
{
    if((m_intCurrentY > m_intMenuY + m_vWidget.size()) || (m_intCurrentY < m_intMenuY+1))
        return TRUE;
    else
        return FALSE;
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

}

void CMenuPage::leftMove(void)
{

}
