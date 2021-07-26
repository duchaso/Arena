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

char** Board::getscreen(WINDOW* win)
{
    int xMax, yMax;
    getmaxyx(win, yMax, xMax);
    char** c = new char*[yMax];
    for(int i = 0; i < yMax; i++)
        c[i] = new char[xMax];
    for(int i = 0; i < yMax; i++)
    {
        for (int j = 0; j < xMax; j++)
        {
            wmove(win, i, j);
            c[i][j] = winch(win);
        }
        
    }
    return c;
}