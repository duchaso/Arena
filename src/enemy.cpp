#include "enemy.hpp"

Enemy::Enemy(WINDOW* win, int x, int y) : x(x), y(y)
{
    character = '$';
    getmaxyx(win, yMax, xMax);
    curwin = win;
}