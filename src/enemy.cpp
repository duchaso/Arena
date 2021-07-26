#include "enemy.hpp"
#include <math.h>

#define INF 10000

Enemy::Enemy(WINDOW* win, int x, int y) : x(x), y(y)
{
    character = '$';
    getmaxyx(win, yMax, xMax);
    curwin = win;
}

struct CustomCompare
{
    bool operator()(std::pair<int, int> p1, std::pair<int, int> p2)
    {
        if (p1.second > p2.second)
            return true;
        else
            return false;
    }       
};


int Enemy::heuristic(int a, int b)
{
	int x1 = a % xMax;
	int y1 = a / xMax;
	int x2 = b % xMax;
	int y2 = b / xMax;
	return (abs(y2 - y1) + abs(x2 - x1));
}

int Enemy::pathfinding(int xs, int ys, int xf, int yf)
{
    //std::pair<int, int> k;

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CustomCompare> q;
	int n = xMax * yMax;
	int k = 0;
	int idf = xf + yf * xMax;
	int* cost = new int[n];
	int* from = new int[n];
    map = Board::getscreen(curwin);
	for (int i = 0; i < n; i++)
	{
		cost[i] = INF;
	}
	int id = xs + ys * xMax;
	q.push(std::make_pair(id, 0));
	cost[id] = 0;
	from[id] = -1;
	//map[ys][xs] = '0';
	while (!q.empty())
	{
		id = q.top().first;
        q.pop();
		//k++;
		if (map[id / xMax - 1][id % xMax] == ' ')
		{

			if (cost[id - xMax] > cost[id] + 1)
			{				
				cost[id - xMax] = cost[id] + 1;
				from[id - xMax] = id;
				//map[id / width - 1][id % width] = k % 10 + 48;
				//map[id / xMax - 1][id % xMax] = '^';
				q.push(std::make_pair(id - xMax, cost[id - xMax] + heuristic(id, idf)));
			}
		}
		if (map[id / xMax + 1][id % xMax] == ' ')
		{
			if (cost[id + xMax] > cost[id] + 1)
			{
				cost[id + xMax] = cost[id] + 1;
				from[id + xMax] = id;
				//map[id / width + 1][id % width] = k % 10 + 48;
				//map[id / xMax + 1][id % xMax] = '^';
                q.push(std::make_pair(id + xMax, cost[id + xMax] + heuristic(id, idf)));
			}
		}
		if (map[id / xMax][id % xMax - 1] == ' ')
		{
			if (cost[id - 1] > cost[id] + 1)
			{
				cost[id - 1] = cost[id] + 1;
				from[id - 1] = id;
				//map[id / width][id % width - 1] = k % 10 + 48;
				//map[id / xMax][id % xMax - 1] = '<';
                q.push(std::make_pair(id - 1, cost[id - 1] + heuristic(id, idf)));
			}
		}
		if (map[id / xMax][id % xMax + 1] == ' ')
		{
			if (cost[id + 1] > cost[id] + 1)
			{
				cost[id + 1] = cost[id] + 1;
				from[id + 1] = id;
				//map[id / width][id % width + 1] = k % 10 + 48;
				//map[id / xMax][id % xMax + 1] = '>';
                q.push(std::make_pair(id + 1, cost[id + 1] + heuristic(id, idf)));
			}
		}
		if (id == (yf * xMax + xf))
		{
			drawPath(from, id, cost[id]);
			Board::setscreen(curwin, map);
			return cost[id];
		}
	}
	
    return 0;
}

void Enemy::drawPath(int* from, int id, int count)
{
	int i = id;
	while (from[i] != -1)
	{
		if (count % 36 > 9)
			map[i / xMax][i % xMax] = 97 + (count % 36 - 10);
		else
			map[i / xMax][i % xMax] = 48 + count % 36;
		i = from[i];
		count--;
	}
	//map[i / xMax][i % xMax] = '0';
}

void Enemy::display()
{
  mvwaddch(curwin, y, x, character);
}