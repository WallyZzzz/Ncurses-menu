#ifndef CMENUPAGE_H
#define CMENUPAGE_H
#include <ncurses.h>
#include <QString>
#include <QStringList>
#include <QVector>
#include "cwidget.h"
#include "cwidgetnumber.h"
#include <QDebug>


class CMenuPage
{
public:
    CMenuPage();
    void initMenu(int width,int height);
    void show(void);
    void showMenu(void);
    void showWidget(void);
    void upMove(void);
    void downMove(void);
    void leftMove(void);
    void rightMove(void);
    bool isOverMenu(void);
    int isNewMenu(void);
    void setMenuName(const QStringList &menuName);
    void setMenuWidget(const QStringList &menuWidget);
    void updateMenuWidget(void);
    void setCurrentY(void);
    void bindNewWidget(const int &widgetLocal, CWidget *widgetName);
    void bindNewMenu(const int &menuMask, const int &menuLink);
    QString searchIndexInMenuWidget(void);
    void clear(void);
private:
    int m_intWidth;
    int m_intHeight;
    int m_intStartX;
    int m_intStartY;
    int m_intCurrentY;
    QStringList m_sMenuName;
    QStringList m_sMenuWidget;
    WINDOW *myWin;
    static int m_intMenuX;
    static int m_intMenuY;
    QVector<int> m_widgetMask;
    QVector<CWidget*> m_widgetName;
    int m_intWidgetNumber;
    QVector<int> m_intMenuMask;
    QVector<int> m_intMenuLink;
    int m_intMenuNumber;
};

#endif // CMENUPAGE_H
