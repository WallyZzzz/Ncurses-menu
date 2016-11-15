#ifndef CWIDGETSTATUS_H
#define CWIDGETSTATUS_H

#include "cwidget.h"
#include <string>

using namespace std;

class CWidgetStatus : public CWidget
{
public:
    CWidgetStatus(const string menuName, const string menuWidget);
    void leftAction(void);
    void rightAction(void);
    string getText(void);
    CMenuPage *isNewMenu(void);
private:
    bool m_boolStatus;
};

#endif // CWIDGETSTATUS_H
