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
    virtual void mvup();
    virtual void mvdown();
    virtual void mvleft();
    virtual void mvright();
    virtual void display();
};

#endif