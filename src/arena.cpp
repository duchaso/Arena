#include <iostream>
#include <ncurses.h>
#include <unistd.h>

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
    p.display();
    Enemy e(board.getwin(), 100, 27);

    mvwaddch(board.getwin(), 21, 95, 'X');
    mvwaddch(board.getwin(), 22, 95, 'X');
    mvwaddch(board.getwin(), 23, 95, 'X');
    mvwaddch(board.getwin(), 24, 95, 'X');
    mvwaddch(board.getwin(), 25, 95, 'X');
    mvwaddch(board.getwin(), 26, 95, 'X');
    mvwaddch(board.getwin(), 27, 95, 'X');
    mvwaddch(board.getwin(), 28, 95, 'X');
    mvwaddch(board.getwin(), 29, 95, 'X');
    mvwaddch(board.getwin(), 30, 95, 'X');
    mvwaddch(board.getwin(), 31, 95, 'X');
    mvwaddch(board.getwin(), 32, 95, 'X');


    mvwaddch(board.getwin(), 21, 96, 'X');
    mvwaddch(board.getwin(), 21, 97, 'X');
    mvwaddch(board.getwin(), 21, 98, 'X');
    mvwaddch(board.getwin(), 21, 99, 'X');
    mvwaddch(board.getwin(), 21, 100, 'X');
    mvwaddch(board.getwin(), 21, 101, 'X');
    mvwaddch(board.getwin(), 21, 102, 'X');
    mvwaddch(board.getwin(), 21, 103, 'X');
    mvwaddch(board.getwin(), 21, 104, 'X');
    mvwaddch(board.getwin(), 21, 105, 'X');

    mvwaddch(board.getwin(), 32, 96, 'X');
    mvwaddch(board.getwin(), 32, 97, 'X');
    mvwaddch(board.getwin(), 32, 98, 'X');
    mvwaddch(board.getwin(), 32, 99, 'X');
    mvwaddch(board.getwin(), 32, 100, 'X');
    mvwaddch(board.getwin(), 32, 101, 'X');
    mvwaddch(board.getwin(), 32, 102, 'X');
    mvwaddch(board.getwin(), 32, 103, 'X');
    mvwaddch(board.getwin(), 32, 104, 'X');
    mvwaddch(board.getwin(), 32, 105, 'X');
    
    e.display();
    //e.mvup();
    //e.display();
    int k = e.gotoplayer(p, board);
    while(p.getmv()!='x')
    {
        p.display();
        wrefresh(board.getwin());
    }
    wrefresh(board.getwin());
    getch();
    endwin();
    std::cout << k << "\n";
}
