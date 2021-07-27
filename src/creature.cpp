#include "creature.hpp"

//constructor

Creature::Creature(WINDOW* win, int x, int y) : x(x), y(y), curwin(win)
{
    getmaxyx(win, yMax, xMax);
}

//methods
void Creature::mvup()
{
  mvwaddch(curwin, y, x, '.');
  y -= 1;
  if(y < 1)
    y = 1;
}

void Creature::mvdown()
{
  mvwaddch(curwin, y, x, '.');
  y += 1;
  if(y > yMax-2)
    y = yMax-2;
}

void Creature::mvleft()
{
  mvwaddch(curwin, y, x, '.');
  x -= 1;
  if(x < 1)
    x = 1;
}

void Creature::mvright()
{
  mvwaddch(curwin, y, x, '.');
  x += 1;
  if(x > xMax-2)
    x = xMax-2;
}

void Creature::display()
{
  mvwaddch(curwin, y, x, character);
}

int Creature::getx()
{
  return x;
}

int Creature::gety()
{
  return y;
}