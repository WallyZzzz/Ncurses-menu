#ifndef CWIDGETNUMBER_H
#define CWIDGETNUMBER_H

#include "cwidget.h"
#include <QString>


class CWidgetNumber : public CWidget
{
public:
    CWidgetNumber();
    void leftAction(void);
    void rightAction(void);
    void initWidget(void);
    QString getText(void);
private:
    int m_intNumber;
};

#endif // CWIDGETNUMBER_H
