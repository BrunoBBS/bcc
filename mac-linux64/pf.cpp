#include <stdio.h>
#include <vector>

#define MSIZE 30

int map[MSIZE][MSIZE];
int mapd[MSIZE][MSIZE];

struct coords
{
public:
	coords(int _x, int _y) : x(_x), y(_y){}
	coords() : x(0), y(0){}
	int x, y;
};

std::vector<coords> pathfinding (coords init, coords end)
{
	std::vector<coords> result;

	printf("init: %d\n", map[init.x][init.y]);

	if(map[init.x][init.y] == -1) return result;
	map[init.x][init.y] = 1;

	map[end.x][end.y] = -2;

	int cnt = 1;
	bool ended = false;

	while (!ended)
	{
		for(int i = 0; !ended && i < MSIZE; i++)
		{
			for (int j = 0; !ended && j < MSIZE; j++) {
				if (!map[j][i])
				{

					if( map[j][i - 1] == cnt ||
						map[j][i + 1] == cnt ||
						map[j - 1][i] == cnt ||
						map[j + 1][i] == cnt
						) map[j][i] = cnt + 1;
				} else if (map[j][i] == -2 && (
						map[j][i - 1] > 0 ||
						map[j][i + 1] > 0 ||
						map[j - 1][i] > 0 ||
						map[j + 1][i] > 0)) ended = true;
			}
		}
		cnt++;
	}
	cnt--;

	coords temp = end;

	for (; cnt >= 0; cnt--)
	{
		result.push_back(temp);
		if(map[temp.x][temp.y - 1] == cnt + 1) temp = coords(temp.x, temp.y - 1);
		if(map[temp.x][temp.y + 1] == cnt + 1) temp = coords(temp.x, temp.y + 1);
		if(map[temp.x - 1][temp.y] == cnt + 1) temp = coords(temp.x - 1, temp.y);
		if(map[temp.x + 1][temp.y] == cnt + 1) temp = coords(temp.x + 1, temp.y);
	}

}

int main ()
{
	coords start, end;
	scanf ("%d %d", &start.x, &start.y);
	scanf ("%d %d", &end.x, &end.y);

	printf("starting at %d %d\n", start.x, start.y);

	for(int i = 0; i < MSIZE; i++)
	{
		for (int j = 0; j < MSIZE; j++) mapd[i][j] = ' ';
	}

	for(int i = 0; i < MSIZE; i++)
	{
		for (int j = 0; j < MSIZE; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			map[j][i] = -tmp;
			mapd[j][i] = tmp?'1':' ';
		}
	}

	for(int i = 0; i < MSIZE; i++)
	{
		map[i][MSIZE - 1] = 
		map[0][i] = 
		map[MSIZE - 1][i] = 
		map[i][0] = -1;
	}

	for(int i = 0; i < MSIZE; i++)
	{
		mapd[i][MSIZE - 1] = 
		mapd[0][i] = 
		mapd[MSIZE - 1][i] = 
		mapd[i][0] = '1';
	}

	std::vector<coords> path = pathfinding(start, end);

	printf("%d\n", path.size());

	for (int i = 0; i < path.size(); i++) mapd[path[i].x][path[i].y] = '*';

	mapd[start.x][start.y] = 'i';
	mapd[end.x][end.y] = 'e';

	for(int i = 0; i < MSIZE; i++)
	{
		for (int j = 0; j < MSIZE; j++) printf ("%c ", mapd[j][i]);
		printf("\n");
	}

}