#ifndef ENEMY_H
#define ENEMY_H

#include<ncurses.h>
#include<vector>
#include<queue>
#include<utility>

#include "creature.hpp"
#include "board.hpp"

class Bot : public Creature
{
protected:
    char** map;
    std::vector<int> path;

public:
    Bot(WINDOW* win, int x, int y);
    int heuristic(int a, int b);
    int pathfinding(int xs, int ys, int xf, int yf);
    std::vector<int> getpath(int* from, int id, int count);

};

#endif