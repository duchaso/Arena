#include "bot.hpp"
#include <math.h>
#include <algorithm>

#define INF 10000

Bot::Bot(WINDOW* win, int x, int y) : Creature(win, x, y)
{
}

class CustomCompare
{
public:
    bool operator()(std::pair<int, int> p1, std::pair<int, int> p2)
    {
        if (p1.second > p2.second)
            return true;
        else
            return false;
    }       
};


int Bot::heuristic(int a, int b)
{
	int x1 = a % xMax;
	int y1 = a / xMax;
	int x2 = b % xMax;
	int y2 = b / xMax;
	return (abs(y2 - y1) + abs(x2 - x1));
}

int Bot::pathfinding(int xs, int ys, int xf, int yf)
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
	while (!q.empty())
	{
		id = q.top().first;
        q.pop();
		if (map[id / xMax - 1][id % xMax] == ' ')
		{

			if (cost[id - xMax] > cost[id] + 1)
			{				
				cost[id - xMax] = cost[id] + 1;
				from[id - xMax] = id;
				q.push(std::make_pair(id - xMax, cost[id - xMax] + heuristic(id, idf)));
			}
		}
		if (map[id / xMax + 1][id % xMax] == ' ')
		{
			if (cost[id + xMax] > cost[id] + 1)
			{
				cost[id + xMax] = cost[id] + 1;
				from[id + xMax] = id;
                q.push(std::make_pair(id + xMax, cost[id + xMax] + heuristic(id, idf)));
			}
		}
		if (map[id / xMax][id % xMax - 1] == ' ')
		{
			if (cost[id - 1] > cost[id] + 1)
			{
				cost[id - 1] = cost[id] + 1;
				from[id - 1] = id;
                q.push(std::make_pair(id - 1, cost[id - 1] + heuristic(id, idf)));
			}
		}
		if (map[id / xMax][id % xMax + 1] == ' ')
		{
			if (cost[id + 1] > cost[id] + 1)
			{
				cost[id + 1] = cost[id] + 1;
				from[id + 1] = id;
                q.push(std::make_pair(id + 1, cost[id + 1] + heuristic(id, idf)));
			}
		}
		if (id == (yf * xMax + xf))
		{
			path = getpath(from, id, cost[id]);
			//Board::setscreen(curwin, map);
			return cost[id];
		}
	}
	
    return 0;
}

std::vector<int> Bot::getpath(int* from, int id, int count)
{
    std::vector<int> path;
	int i = id;
	while (from[i] != -1)
	{
        if (i - from[i] > 1)
            path.push_back(0);
        else if (i - from[i] == 1)
            path.push_back(1);
        else if (i - from[i] == -1)
            path.push_back(2);
        else if (i - from[i] < -1)
            path.push_back(3);
		i = from[i];
	}
    //reverse(path.begin(), path.end());
    return path;
}