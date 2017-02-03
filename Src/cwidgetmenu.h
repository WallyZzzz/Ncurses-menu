#ifndef CWIDGETMENU_H
#define CWIDGETMENU_H
#include "cwidget.h"
#include <string>

using namespace std;

class CWidgetMenu : public CWidget
{
public:
    CWidgetMenu(const string menuName, CMenuPage *nextMenu);
    CMenuPage *isNewMenu(void);
    string getText(void);
    void leftAction(void);
    void rightAction(void);
private:
    CMenuPage *m_pNextMenu;
};

#endif // CWIDGETMENU_H
