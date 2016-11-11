#ifndef CMENUPAGE_H
#define CMENUPAGE_H
#include <ncurses.h>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <QDebug>
#include <iostream>

class CWidget;

using namespace std;

class CMenuPage
{
public:
    CMenuPage();
    void initMenu(int width,int height);
    void bindNewWidget(CWidget *newWidget);
    void show(void);
    void showWidget(void);
    void upMove(void);
    void downMove(void);
    void leftMove(void);
    void rightMove(void);
    bool isOverMenu(void);
    int isNewMenu(void);
    void setCurrentY(void);
    void clear(void);
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
};

#endif // CMENUPAGE_H
