#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Poker
{								// 定义“扑克”结构体
	int suit;					// 花色
	int size;					// 牌面数（包括A、J、Q、K）
};
Poker p[5];

void swap(int &a, int &b)
{
	a ^= b ^= a ^= b;
}

void init()
{
	cout << "正在洗牌……" << endl;
	cout << "正在抽出5张牌……" << endl;
	unsigned seed = time(0);
	srand(seed);
	for (int i = 0; i < 5; i++)
		p[i].suit = i + 1;
	for (int i = 0; i < 13; i++)
		p[i].size = i + 1;

	int j, k;
	for (int i = 0; i < 5; i++)
	{
		j = rand() % (5 - i) + i;
		k = p[i].suit;
		p[i].suit = p[j].suit;
		p[j].suit = k;
	}
}

	int main()
	{
		init();
		for(int i=0;i<5;i++)cout<<p[i].suit<<" "<<p[i].size<<endl;
		return 0;
	}