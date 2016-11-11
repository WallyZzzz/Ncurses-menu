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

    while(1)
    {
//      inputKey.getKey();
//      if(inputKey.isUp())
//          pageCtrl.moveUp();
//      if(inputKey.isDown())
//          pageCtrl.moveDown();
//      if(inputKey.isLeft())
//          pageCtrl.moveLeft();
//      if(inputKey.isRight())
//          pageCtrl.moveRight();
//      if(inputKey.isEnter())
//          pageCtrl.enterMenu();
//      if(inputKey.isQuit())
//          pageCtrl.quitMenu();
    }
    return 0;
}
