#include <iostream>
#include <ncurses.h>

#include "board.hpp"
#include "arena.hpp"
#include "player.hpp"
#include "enemy.hpp"

int main(int, char**) {
    initscr();
    noecho();
    curs_set(0);

    Board board(35, 120, 0, 0);
    Player p(board.getwin(), 5, 5);
    mvwaddch(board.getwin(), 3, 5, 'X');
    mvwaddch(board.getwin(), 3, 6, 'X');
    mvwaddch(board.getwin(), 3, 7, 'X');
    mvwaddch(board.getwin(), 4, 8, 'X');
    mvwaddch(board.getwin(), 5, 8, 'X');
    mvwaddch(board.getwin(), 6, 8, 'X');
    mvwaddch(board.getwin(), 7, 7, 'X');
    mvwaddch(board.getwin(), 6, 9, 'X');
    mvwaddch(board.getwin(), 7, 8, 'X');
    mvwaddch(board.getwin(), 7, 7, 'X');
    mvwaddch(board.getwin(), 7, 6, 'X');
    mvwaddch(board.getwin(), 7, 5, 'X');
    mvwaddch(board.getwin(), 7, 4, 'X');
    mvwaddch(board.getwin(), 7, 3, 'X');
    mvwaddch(board.getwin(), 7, 2, 'X');
    p.display();
    Enemy e(board.getwin(), 100, 27);
    int k = e.pathfinding(5, 5, 100, 26);
    e.display();
    while(p.getmv()!='x')
    {
        p.display();
        wrefresh(board.getwin());
    }
    wrefresh(board.getwin());
    getch();
    endwin();
}
