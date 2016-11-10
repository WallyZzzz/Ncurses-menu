#ifndef CWIDGETSTATUS_H
#define CWIDGETSTATUS_H

#include "cwidget.h"


class CWidgetStatus : public CWidget
{
public:
    CWidgetStatus();
    void leftAction(void);
    void rightAction(void);
    void initWidget(void);
    QString getText(void);
private:
    bool m_myStatus;
};

#endif // CWIDGETSTATUS_H
