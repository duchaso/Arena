#include "player.hpp"


//constructor
Player::Player(WINDOW* win, int x1, int y1) 
{
    x = x1;
    y = y1;
    getmaxyx(win, yMax, xMax);
    curwin = win;
    keypad(curwin, true);
}


//methods
int Player::getmv()
{
  int choice = wgetch(curwin);
  switch(choice)
  {
    case KEY_UP:
      mvup();
      break;
    case KEY_DOWN:
      mvdown();
      break;
    case KEY_LEFT:
      mvleft();
      break;
    case KEY_RIGHT:
      mvright();
      break;
    default:
      break;
  }
  return choice;
}