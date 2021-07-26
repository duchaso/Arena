#include <iostream>
#include <ncurses.h>

#include "board.hpp"
#include "arena.hpp"
#include "player.hpp"
int main(int, char**) {
    initscr();
    noecho();
    curs_set(0);

    Board board(35, 120, 0, 0);
    Player p(board.getwin(), 5, 5);
    while(p.getmv()!='x')
    {
        p.display();
        wrefresh(board.getwin());
    }

    getch();
    endwin();
}
