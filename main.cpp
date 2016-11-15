#include <ncurses.h>
#include <iostream>
#include "ckeyread.h"
#include "cmenupage.h"
#include "cwidget.h"
#include "cwidgetstatus.h"
#include "cwidgetnumber.h"
#include "cmenuctrl.h"
#include "cwidgetmenu.h"

int main(void)
{
    initscr();
    cbreak();
    curs_set(0);

    CKeyRead inputKey;
    CMenuCtrl menuCtrl;

    CMenuPage *homePage = new CMenuPage(60, 20);
    CMenuPage *newPage = new CMenuPage(40, 20);

    homePage->newWidgetNumber("Test menu 1.     ", "20");
    homePage->newWidgetStatus("Test menu 2.     ", "FALSE");
    homePage->newWidgetMenu("Test menu 3.     ", newPage);

    menuCtrl.setHomePage(homePage);
    menuCtrl.show();
    while(1)
    {
      inputKey.getKey();
      if(inputKey.isUp())
          menuCtrl.moveUp();
      if(inputKey.isDown())
          menuCtrl.moveDown();
      if(inputKey.isLeft())
          menuCtrl.moveLeft();
      if(inputKey.isRight())
          menuCtrl.moveRight();
      if(inputKey.isEnter())
          menuCtrl.enterMenu();
      if(inputKey.isQuit())
          menuCtrl.quitMenu();
    }
    return 0;
}
