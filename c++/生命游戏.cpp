#include<iostream>
using namespace std;

const int map_x = 34, map_y = 45;
int map[map_x][map_y] = { 0 };

void print_map()
{
	for (int i = 0; i < map_x; ++i)
	{
		for (int j = 0; j < map_y; ++j)
			cout << map[i][j];
		cout << endl;
	}
}

int count_life(auto tmp, int x, int y)
{
	int sum;
	if (y - 1 >= 0 && x - 1 >= 0 && tmp[x - 1][y - 1] == 1)
		++sum;					// 左上
	if (x - 1 >= 0 && tmp[x - 1][y] == 1)
		++sum;					// 上
	if (x - 1 >= 0 && y + 1 < 45 && tmp[x - 1][y+1] == 1)
		++sum;					// 右上
	if (y - 1 >= 0 && tmp[x][y - 1] == 1)
		++sum;					// 左
	if (y + 1 < 45 && tmp[x][y + 1] == 1)
		++sum;					// 右
	if (x + 1 < 34 && y - 1 >= 0 && tmp[x + 1][y - 1] == 1)
		++sum;					// 左下
	if (x + 1 < 34 && tmp[x + 1][y] == 1)
		++sum;					// 下
	if (x + 1 < 34 && y + 1 < 45 && tmp[x + 1][y + 1] == 1)
		++sum;					// 右下
	return sum;
}

/*void change_cell(int tmp, int y, int x)
{
	if (map[x][y] == 0 && count_life(x, y) == 3)
		map[x][y] = 1;
	else if (map[x][y] == 1)
	{
		if (count_life(x, y) < 2)
			map[x][y] = 0;
		else if (count_life(x, y) > 3)
			map[x][y] = 0;
	}
}*/

void update()
{
	int tmp[map_x][map_y];
	for (int i = 0; i < map_x; ++i)
		for (int j = 0; j < map_y; ++j)
			tmp[i][j] = map[i][j];
	for (int x = 0; x < 34; ++x)
		for (int y = 0; y < 45; ++y)
		{
			if (tmp[x][y] == 0 && count_life(tmp, x, y) == 3)
				map[x][y] = 1;
			else if (tmp[x][y] == 1)
			{
				if (count_life(tmp, x, y) < 2)
					map[x][y] = 0;
				else if (count_life(tmp, x, y) > 3)
					map[x][y] = 0;
			}
		}
}

int main()
{
	for (int i = 0, x, y; i < 5; ++i)
	{
		cin >> y >> x;
		map[x][y] = 1;
	}
	print_map();
	update();
	cout << endl;
	print_map();
	cout << "run stopped!" << endl;
	return 0;
}

	/* 滑翔机坐标： 1 0 2 1 0 2 1 2 2 2 */