#ifndef CWIDGET_H
#define CWIDGET_H
#include <QString>

class CWidget
{
public:
    CWidget();
    virtual void leftAction(void) = 0;
    virtual void rightAction(void) = 0;
    virtual void initWidget(void) = 0;
    virtual QString getText(void) = 0;
};

#endif // CWIDGET_H
