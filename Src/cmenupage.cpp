#include "cmenupage.h"
#include "cwidget.h"


int CMenuPage::m_intMenuX = 12;
int CMenuPage::m_intMenuY = 2;


CMenuPage::CMenuPage(int width, int height)
{
    m_intWidth = width;
    m_intHeight = height;
    m_intStartX = (COLS - m_intWidth)/2;
    m_intStartY = (LINES - m_intHeight)/2;

    myWin = newwin(m_intHeight, m_intWidth, m_intStartY, m_intStartX);

    m_intCurrentY = m_intMenuY;
}

void CMenuPage::bindNewWidget(CWidget *newWidget)
{
    m_vWidget.push_back(newWidget);
}

void CMenuPage::setCurrentY(void)
{
    mvwaddch(myWin, m_intCurrentY, m_intMenuX - 2, '#');
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
       mvwprintw(myWin, m_intMenuY + (itWidget - m_vWidget.begin()), m_intMenuX, (*itWidget)->getText().c_str());
}

bool CMenuPage::isOverMenu(void)
{
    if((m_intCurrentY > m_intMenuY + m_vWidget.size() - 1 ) || (m_intCurrentY < m_intMenuY))
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
        mvwaddch(myWin, m_intCurrentY, m_intMenuX-2, '#');
        mvwaddch(myWin, m_intCurrentY -1, m_intMenuX-2, ' ');
        show();
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
        mvwaddch(myWin, m_intCurrentY, m_intMenuX-2, '#');
        mvwaddch(myWin, m_intCurrentY + 1, m_intMenuX-2, ' ');
        show();
    }
}

void CMenuPage::rightMove(void)
{
    m_vWidget.at(m_intCurrentY - m_intMenuY)->rightAction();
    show();
}

void CMenuPage::leftMove(void)
{
    m_vWidget.at(m_intCurrentY - m_intMenuY)->leftAction();
    show();
}

CMenuPage *CMenuPage::enterMenu(void)
{
    return m_vWidget.at(m_intCurrentY - m_intMenuY)->isNewMenu();
}

void CMenuPage::newWidgetMenu(const string menuName, CMenuPage *nextMenu)
{
    newWidget = new CWidgetMenu(menuName, nextMenu);
    bindNewWidget(newWidget);
}

void CMenuPage::newWidgetNumber(const string menuName, const string menuWidget)
{
    newWidget = new CWidgetNumber(menuName, menuWidget);
    bindNewWidget(newWidget);
}

void CMenuPage::newWidgetStatus(const string menuName, const string menuWidget)
{
    newWidget = new CWidgetStatus(menuName, menuWidget);
    bindNewWidget(newWidget);
}

WINDOW *CMenuPage::getWin(void)
{
    return myWin;
}
