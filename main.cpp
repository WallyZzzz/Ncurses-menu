#include <ncurses.h>
#include <iostream>
#include "ckeyread.h"
#include "cmenupage.h"
#include "cwidget.h"
#include "cwidgetstatus.h"
#include "cwidgetnumber.h"
#include "cmenuctrl.h"


int main(void)
{
    initscr();
    cbreak();
    curs_set(0);

    CKeyRead inputKey;
    CWidget *widget;

    CMenuPage *homePage = new CMenuPage;
    CWidgetNumber homeNumber;
    widget = &homeNumber;
    homeNumber.initWidget("Text menu 1.     ", "20", NULL);
    homePage->bindNewWidget(widget);
    CWidgetStatus homeStatus;
    widget = &homeStatus;
    widget->initWidget("Text menu 2.      ", "true", NULL);
    homePage->bindNewWidget(widget);

    homePage->initMenu(60,20);
    homePage->show();
    while(1)
    {
      inputKey.getKey();
      if(inputKey.isUp())
          homePage->upMove();
      if(inputKey.isDown())
          homePage->downMove();
      if(inputKey.isLeft())
          homePage->leftMove();
      if(inputKey.isRight())
          homePage->rightMove();
      if(inputKey.isEnter());
          //pageCtrl.enterMenu();
      if(inputKey.isQuit())
          break;
    }
    return 0;
}
