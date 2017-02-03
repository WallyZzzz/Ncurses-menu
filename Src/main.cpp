#include <ncurses.h>
#include <iostream>
#include "ckeyread.h"
#include "cmenupage.h"
#include "cmenuctrl.h"

int main(void)
{
    initscr();
    setlocale(LC_ALL, "");
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    curs_set(0);
    noecho();
    erase();
    refresh();

    CKeyRead inputKey;
    CMenuCtrl menuCtrl;

    CMenuPage *homePage = new CMenuPage(60, 20);
    CMenuPage *firstPage = new CMenuPage(50, 20);
    CMenuPage *secondPage = new CMenuPage(40, 20);
    CMenuPage *thirtPage = new CMenuPage(30, 20);

    homePage->newWidgetNumber("Test menu 1.     ", "20");
    homePage->newWidgetStatus("Test menu 2.     ", "FALSE");
    homePage->newWidgetMenu("Test menu 3.     ", firstPage);

    firstPage->newWidgetStatus("Test menu 2-1.  ", "FALSE");
    firstPage->newWidgetNumber("Test menu 2-2   ", "50");
    firstPage->newWidgetNumber("Test menu 2-3.  ", "40");
    firstPage->newWidgetMenu("Test menu 2-4.  ", secondPage);

    secondPage->newWidgetMenu("Test menu 3-1.  ", thirtPage);

    menuCtrl.setHomePage(homePage);
    menuCtrl.show();
    while(1)
    {
        inputKey.getKey(menuCtrl.currentPage());
        menuCtrl.readKey(inputKey.readKey());
    }
    endwin();
    return 0;
}
