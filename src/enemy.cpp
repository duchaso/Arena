#include "enemy.hpp"
#include <math.h>
#include <unistd.h>


Enemy::Enemy(WINDOW* win, int x, int y) : Bot(win, x, y)
{
    character = '$';
}

int Enemy::gotoplayer(Player p, Board board)
{
	int k;
	k = pathfinding(p.getx() - 1, p.gety(), x - 1, y);
	for (int i = 0; i < path.size(); i++)
	{
		switch (path[i])
		{
		case 0:
			mvup();
			break;
		case 1:
			mvleft();
			break;
		case 2:
			mvright();
			break;
		case 3:
			mvdown();
			break;
		default:
			break;
		}
        display();
        wrefresh(board.getwin());
        usleep(50000);
	}
	return k;
}