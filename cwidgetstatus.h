#ifndef CWIDGETSTATUS_H
#define CWIDGETSTATUS_H

#include "cwidget.h"
#include <string>

using namespace std;

class CWidgetStatus : public CWidget
{
public:
    CWidgetStatus();
    void leftAction(void);
    void rightAction(void);
    void initWidget(const string menuName, const string menuString, CMenuPage *nextMenu);
    string getText(void);
    CMenuPage *isNewMenu(void);
private:
    bool m_boolStatus;
};

#endif // CWIDGETSTATUS_H
