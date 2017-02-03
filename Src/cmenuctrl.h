#ifndef CMENUCTRL_H
#define CMENUCTRL_H
#include <ncurses.h>
#include <vector>
#include "cmenupage.h"
#include <stack>
#include <algorithm>
#include "ckeyread.h"

using namespace std;

class CMenuCtrl
{
public:
    CMenuCtrl();
    void initMenuCtrl(void);
    void show(void);
    void setHomePage(CMenuPage *newMenu);
    void enterMenu(void);
    void quitMenu(void);
    void moveUp(void);
    void moveDown(void);
    void moveLeft(void);
    void moveRight(void);
    WINDOW *currentPage(void);
    void readKey(char key);
private:
    CMenuPage *m_pMenuPage;
    stack<CMenuPage*> preMenu;
};

#endif // CMENUCTRL_H
