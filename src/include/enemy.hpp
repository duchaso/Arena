#ifndef ENEMY_H
#define ENEMY_H

#include<ncurses.h>
#include<vector>
#include<queue>
#include<utility>

#include "board.hpp"

class Enemy
{
private:
    char character;
    int x, y;
    int xMax, yMax;
    char** map;
    WINDOW* curwin;
    std::vector<int> path;

public:
    Enemy(WINDOW* win, int x, int y);
    int heuristic(int a, int b);
    int pathfinding(int xs, int ys, int xf, int yf);
    void display();
    void drawPath(int* from, int id, int count);

};

#endif