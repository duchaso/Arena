#include <iostream>
#include <ncurses.h>

#include "board.hpp"
#include "arena.hpp"

int main(int, char**) {
    initscr();
    noecho();
    curs_set(0);

    Board board(35, 120, 0, 0);

    getch();
    endwin();
}
