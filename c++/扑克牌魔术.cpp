#include<iostream>
#include<cstdlib>
#include<ctime>
//#include<algorithm>
//#include<cmath>
using namespace std;

struct Poker    //定义“扑克”结构体
{
    int suit;   //花色
    int points;   //点数
};
Poker p[5];
int d;  //两牌之间的“距离”

void swap(Poker &a, Poker &b)   //交换函数
{
    swap(a.points, b.points);
    swap(a.suit, b.suit);
}

void random_poker() //洗牌函数
{
    for (int i = 0; i < 5; i++)
        p[i].suit = rand() % 4 + 1;
    for (int i = 0; i < 5; i++)
        p[i].points = rand() % 13 + 1;
}

int abs(int a)
{
    return (a >= 0) ? a : (-a);
}

void bubble_sort(Poker arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j].suit > arr[j + 1].suit)
            {
                swap(arr[j].suit, arr[j + 1].suit);
                swap(arr[j].points, arr[j + 1].points);
            }
            else if (arr[j].suit == arr[j + 1].suit)
            {
                if (arr[j].points > arr[j + 1].points)
                {
                    swap(arr[j].suit, arr[j + 1].suit);
                    swap(arr[j].points, arr[j + 1].points);
                }
            }
        }

}

void move_poker(int a)
{
    bubble_sort(p + 1, 3);
    switch (a)
    {
    case 1: break;
    case 2: swap(p[2],p[3]); break;
    case 3: swap(p[1],p[2]); break;
    case 4: swap(p[2],p[3]); swap(p[1],p[3]); break;
    case 5: swap(p[2],p[3]); swap(p[1],p[2]); break;
    case 6: swap(p[1],p[3]); break;
    }
}

void init() //初始化
{
    cout << "正在洗牌……" << endl;
    cout << "正在抽出5张牌……" << endl;
    unsigned seed = time(0);
    srand(seed);
    random_poker();
    for (int i = 0; i < 5; i++) //检查是否有重复的牌
    {
        for (int j = 0; j < 5; j++)
        {
            if (p[i].points == p[j].points && p[i].suit == p[j].suit && i != j)
                random_poker();
        }
    }
}

void modeOne()
{
    for (int i = 0; i < 5; i++) //遍历整幅牌，找出2张花色相同的牌放在第1张和第5张
    {
        for (int j = 0; j < 5; j++)
        {
            if (p[i].suit == p[j].suit && i != j)
            {
                swap(p[i].suit, p[0].suit);
                swap(p[i].points, p[0].points);
                swap(p[j].suit, p[4].suit);
                swap(p[j].points, p[4].points);
                i = j = 5;  //跳出两层循环
            }
            else
                continue;
        }
    }
    d = (abs(p[0].points - p[4].points) > 6) ? (13 - abs(p[0].points - p[4].points)) : (abs(p[0].points - p[4].points));

    move_poker(d);
}

int main()
{
    init();
    modeOne();
    for(int i = 0; i < 5; i++)cout << p[i].suit << " " << p[i].points << endl;
    //cout << d << endl;
    return 0;
}
