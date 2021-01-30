#include<iostream>
using namespace std;

int countPowMod(int, int ,int);

int main()
{
	int m, c, m_, e=157, n=15481, d=5045;
	cout << "请输入明文m：" << endl;
	cin >> m;
	c = countPowMod(m, e, n);
	cout << "密文c = " << c << endl;
	m_ = countPowMod(c, d, n);
	cout << "解密后的明文m_ = " << m_ << endl;
    
   return 0;
}

int countPowMod(int a, int power, int mod)
{
   unsigned long long result = 1;
   unsigned long long temp = a % mod;
   while (power >= 1) {
      if (power % 2 != 0) {
         result = (result * temp) % mod;   
      }
      temp = (temp * temp) % mod;
      power /= 2;   
   }
   return result;
}