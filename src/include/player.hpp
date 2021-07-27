#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include "board.hpp"
#include "creature.hpp"

class Player : public Creature
{
public:
    int  getmv();
public:
    Player(WINDOW* win, int x, int y);
};


#endif