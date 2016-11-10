#include <ncurses.h>
#include <QString>
#include <QStringList>
#include <iostream>
#include "ckeyread.h"
#include "cmenupage.h"
#include "cwidget.h"
#include "cwidgetstatus.h"
#include "cwidgetnumber.h"
#include "cmenuctrl.h"

QStringList homeMenuName,firstMenuName;
QStringList homeMenuWidget,firstMenuWidget;

void initMenu(void);

int main(void)
{
    initMenu();

    initscr();
    cbreak();
    curs_set(0);

    CWidgetNumber homePageNumberWidget;
    CWidgetStatus homePageStatusWidget;

    CMenuPage *homePage = new CMenuPage;
    homePage->initMenu(60, 20);
    homePage->setMenuName(homeMenuName);
    homePage->setMenuWidget(homeMenuWidget);

    CMenuPage *firstPage = new CMenuPage;
    firstPage->initMenu(50, 20);
    firstPage->setMenuName(firstMenuName);
    firstPage->setMenuWidget(firstMenuWidget);

    homePage->bindNewMenu(2, 1);

    CWidget *pageWidget = &homePageNumberWidget;
    homePage->bindNewWidget(3,pageWidget);
    pageWidget = &homePageStatusWidget;
    homePage->bindNewWidget(4,pageWidget);

    CMenuCtrl pageCtrl;
    pageCtrl.addMenuPage(homePage);
    pageCtrl.addMenuPage(firstPage);
    pageCtrl.show();

    CKeyRead inputKey;

    while(1)
    {
      inputKey.getKey();
      if(inputKey.isUp())
          pageCtrl.moveUp();
      if(inputKey.isDown())
          pageCtrl.moveDown();
      if(inputKey.isLeft())
          pageCtrl.moveLeft();
      if(inputKey.isRight())
          pageCtrl.moveRight();
      if(inputKey.isEnter())
          pageCtrl.enterMenu();
      if(inputKey.isQuit())
          pageCtrl.quitMenu();
    }
    return 0;
}

void initMenu(void)
{
    homeMenuName << "Test menu 1."
                 << "Test menu 2."
                 << "Test menu 3."
                 << "Test menu 4."
                 << "Test menu 5."
                 << "Test menu 6.";

    homeMenuWidget << ">>"
                   << ">>"
                   << "  "
                   << "  "
                   << "  "
                   << ">>";

    firstMenuName << "Test menu 1-1."
                  << "Test menu 1-2."
                  << "Test menu 1-3."
                  << "Test menu 1-4.";

    firstMenuWidget << ">>"
                    << "  "
                    << ">>"
                    << "  ";
}

