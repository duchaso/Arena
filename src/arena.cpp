#include <iostream>
#include <ncurses.h>

#include "arena.hpp"

int main(int, char**) {
    initscr();
    printw("Hello");
    getch();
    endwin();
}
