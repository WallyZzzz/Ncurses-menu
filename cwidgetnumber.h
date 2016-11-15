#ifndef CWIDGETNUMBER_H
#define CWIDGETNUMBER_H

#include "cwidget.h"
#include <string>
#include <sstream>

using namespace std;

class CWidgetNumber : public CWidget
{
public:
    CWidgetNumber(const string menuName, const string menuWidget);
    void leftAction(void);
    void rightAction(void);
    string getText(void);
    CMenuPage *isNewMenu(void);
private:
    int m_intNumber;
};

#endif // CWIDGETNUMBER_H
