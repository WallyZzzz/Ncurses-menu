#ifndef CWIDGETMENU_H
#define CWIDGETMENU_H
#include "cwidget.h"
#include <string>

using namespace std;

class CWidgetMenu : public CWidget
{
public:
    CWidgetMenu();
    void initWidget(const string menuName, const string menuWidget, CMenuPage *nextMenu);
    CMenuPage *isNewMenu(void);
    string getText(void);
private:
    CMenuPage *m_pNextMenu;
};

#endif // CWIDGETMENU_H
