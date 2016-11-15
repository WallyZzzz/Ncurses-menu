#ifndef CMENUPAGE_H
#define CMENUPAGE_H
#include <ncurses.h>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <QDebug>
#include <iostream>
#include "cwidgetmenu.h"
#include "cwidgetnumber.h"
#include "cwidgetstatus.h"

class CWidget;

using namespace std;

class CMenuPage
{
public:
    CMenuPage(int width, int height);
    void bindNewWidget(CWidget *newWidget);
    void show(void);
    void showWidget(void);
    void upMove(void);
    void downMove(void);
    void leftMove(void);
    void rightMove(void);
    bool isOverMenu(void);
    void setCurrentY(void);
    void clear(void);
    CMenuPage *enterMenu(void);
    void newWidgetMenu(const string menuName, CMenuPage *nextMenu);
    void newWidgetStatus(const string menuName, const string menuWidget);
    void newWidgetNumber(const string menuName, const string menuWidget);
private:
    vector<CWidget*> m_vWidget;
    int m_intWidth;
    int m_intHeight;
    int m_intStartX;
    int m_intStartY;
    int m_intCurrentY;
    WINDOW *myWin;
    static int m_intMenuX;
    static int m_intMenuY;
    CWidget *newWidget;
};

#endif // CMENUPAGE_H
