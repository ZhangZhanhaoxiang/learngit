#include<iostream>
using namespace std;

const int N = 101;
int a[N], top = 0;
void push(int);
void pop();
int getTop();
void clear();

int main()
{
	int num, cnt = 0;
	cin >> num;
	while (num)
	{
		push(num%2);
		num /=2;
		cnt++;
	}
	for (int i=1; i <= cnt; i++)
	{
		cout << getTop();
		pop();
	}
	return 0;
}

void push(int m)
{
	if (top < N)
		a[++top] = m;
}

void pop()
{
	if (top > 0)
		top--;
}

int getTop()
{
	return a[top];
}

void clear()
{
		top = 0;
}