#ifndef CWIDGETMENU_H
#define CWIDGETMENU_H
#include "cwidget.h"


class CWidgetMenu : public CWidget
{
public:
    CWidgetMenu();
    void initWidget(const string menuName, const string menuWidget, CMenuPage *nextMenu);
    bool isNewMenu(void);
private:
    CMenuPage *m_pNextMenu;
};

#endif // CWIDGETMENU_H
