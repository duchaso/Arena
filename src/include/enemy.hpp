#ifndef BOTH
#define BOT_H

#include <ncurses.h>

#include "bot.hpp"
#include "player.hpp"

class Enemy : public Bot
{
private:

public:
    Enemy(WINDOW* win, int x, int y);
    int gotoplayer(Player p, Board board);
};

#endif