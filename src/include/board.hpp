#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>

class Board
{
private:
    int height, width;
    int x, y;

    WINDOW* win; 
public:
    WINDOW* getwin();
public:
    Board(int height, int width, int x, int y);
};

#endif