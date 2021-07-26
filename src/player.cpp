#include "player.hpp"


//constructor
Player::Player(WINDOW* win, int x, int y) : x(x), y(y) 
{
    getmaxyx(win, yMax, xMax);
    curwin = win;
    keypad(curwin, true);
}




void Player::mvup()
{
  mvwaddch(curwin, y, x, ' ');
  y -= 1;
  if(y < 1)
    y = 1;
}

void Player::mvdown()
{
  mvwaddch(curwin, y, x, ' ');
  y += 1;
  if(y > yMax-2)
    y = yMax-2;
}

void Player::mvleft()
{
  mvwaddch(curwin, y, x, ' ');
  x -= 1;
  if(x < 1)
    x = 1;
}

void Player::mvright()
{
  mvwaddch(curwin, y, x, ' ');
  x += 1;
  if(x > xMax-2)
    x = xMax-2;
}

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

void Player::display()
{
  mvwaddch(curwin, y, x, character);
}