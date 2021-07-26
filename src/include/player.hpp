#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include "board.hpp"

class Player 
{
private:
    WINDOW* curwin;
    char character = '@';
    int x, y;
    int xMax, yMax;
public:
    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    int  getmv();
    void display();
public:
    Player(WINDOW* win, int x, int y);
};


#endif
