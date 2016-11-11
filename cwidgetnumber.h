#ifndef CWIDGETNUMBER_H
#define CWIDGETNUMBER_H

#include "cwidget.h"
#include <string>
#include <sstream>

using namespace std;

class CWidgetNumber : public CWidget
{
public:
    CWidgetNumber();
    void leftAction(void);
    void rightAction(void);
    void initWidget(const string menuName, const string menuWidget, CMenuPage *nextMenu);
    string getText(void);
    CMenuPage *isNewMenu(void);
private:
    int m_intNumber;
};

#endif // CWIDGETNUMBER_H
