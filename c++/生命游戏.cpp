#include<iostream>
// sleep()函数的头文件（完全可以不需要）
#if defined(__linux__)
	// Linux系统
#include<unistd.h>
#elif defined(_WIN32)
	// Windows系统
#include<windows.h>
#endif
using std::cout;
using std::cin;
using std::endl;

// 定义地图行数和列数
const int map_x = 80, map_y = 70;
int map[map_x][map_y] = { 0 };

// 打印地图
void print_map()
{
	for (int i = 0; i < map_x; ++i)
	{
		for (int j = 0; j < map_y; ++j)
			map[i][j] == 1 ? cout << "\u25a0" : cout << "\u25a1";
		cout << endl;
	cout << endl;
}

// 统计当前格子周围8格子的生命总数
int count_life(auto tmp, int x, int y)
{
	int sum = 0;				// 变量在使用前应初始化（一个找了半小时的bug）
	if (y - 1 >= 0 && x - 1 >= 0 && tmp[x - 1][y - 1] == 1)
		++sum;					// 左上
	if (x - 1 >= 0 && tmp[x - 1][y] == 1)
		++sum;					// 上
	if (x - 1 >= 0 && y + 1 < map_y && tmp[x - 1][y + 1] == 1)
		++sum;					// 右上
	if (y - 1 >= 0 && tmp[x][y - 1] == 1)
		++sum;					// 左
	if (y + 1 < map_y && tmp[x][y + 1] == 1)
		++sum;					// 右
	if (x + 1 < map_x && y - 1 >= 0 && tmp[x + 1][y - 1] == 1)
		++sum;					// 左下
	if (x + 1 < map_x && tmp[x + 1][y] == 1)
		++sum;					// 下
	if (x + 1 < map_x && y + 1 < map_y && tmp[x + 1][y + 1] == 1)
		++sum;					// 右下
	return sum;
}

// 更新整个地图
void update()
{
	// 由于应按照上一代的地图更新，故创建一个和原地图一模一样的副本
	int tmp[map_x][map_y];
	// 复制原地图到副本
	for (int i = 0; i < map_x; ++i)
		for (int j = 0; j < map_y; ++j)
			tmp[i][j] = map[i][j];
	// 根据游戏规则遍历并更新地图
	for (int x = 0; x < map_x; ++x)
		for (int y = 0; y < map_y; ++y)
		{
			// 规则1：若当前格子无生命且其周围格子生命总数为3时，当前格子变成1（生命能繁殖出新生命）
			if (tmp[x][y] == 0 && count_life(tmp, x, y) == 3)
				map[x][y] = 1;
			// 若当前格子有生命
			else if (tmp[x][y] == 1)
			{
				// 规则2：若当前格子有生命且其周围格子生命总数小于2时，当前格子变成0（生命害怕孤独）
				if (count_life(tmp, x, y) < 2)
					map[x][y] = 0;
				// 规则3：若当前格子有生命，且其周围格子生命总数大于3时，当前格子变成0（生命不喜欢拥挤）
				else if (count_life(tmp, x, y) > 3)
					map[x][y] = 0;
			}
		}
	// 规则4：否则保持不变
}

int main()
{
	cout << "请输入有生命的格子的个数及其坐标：" << endl;
	int n;
	cin >> n;
	for (int i = 1, x, y; i <= n; ++i)
	{
		cin >> y >> x;
		map[x][y] = 1;
	}
	print_map();
	for (int i = 1; i <= 100; ++i)
	{
		update();
		print_map();
		usleep(1000 * 50);		// 延时(1000*n)微秒
		system("clear");		// 清空控制台
	}
	cout << "Run Successfully!" << endl;
	return 0;
}

	/* 滑翔机坐标： 1 0 2 1 0 2 1 2 2 2 */