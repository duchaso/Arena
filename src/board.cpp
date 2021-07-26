#include "board.hpp"

//constructor
Board::Board(int height, int width, int x, int y)
    : height(height), width(width), x(x), y(y)
{
    board = newwin(height, width, x, y);
    box(board, 0, 0);
    refresh();
    wrefresh(board);
}