#include "board.hpp"

//constructor
Board::Board(int height, int width, int x, int y)
    : height(height), width(width), x(x), y(y)
{
    win = newwin(height, width, x, y);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
}


WINDOW* Board::getwin()
{
    return win;
}