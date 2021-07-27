#ifndef CREATURE_H
#define CREATURE_H

#include "ncurses.h"

class Creature
{
protected:
    WINDOW* curwin;
    char character;
    int x, y;
    int xMax, yMax;
public:
    Creature(WINDOW* win, int x, int y);
    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    void display();
    int getx();
    int gety();
};

#endif