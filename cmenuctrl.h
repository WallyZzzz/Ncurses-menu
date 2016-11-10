#ifndef CMENUCTRL_H
#define CMENUCTRL_H
#include <ncurses.h>
#include <vector>
#include "cmenupage.h"
#include <stack>
#include <algorithm>
#include <QDebug>

using namespace std;

class CMenuCtrl
{
public:
    CMenuCtrl();
    void initMenuCtrl(void);
    void show(void);
    void addMenuPage(CMenuPage *newMenu);
    void enterMenu(void);
    void quitMenu(void);
    void moveUp(void);
    void moveDown(void);
    void moveLeft(void);
    void moveRight(void);
private:
    vector<CMenuPage*> m_myMenuP;
    stack<CMenuPage*> preMenu;
    int m_intMenuPageNum;
    int m_intCurrentMenu;
};

#endif // CMENUCTRL_H
