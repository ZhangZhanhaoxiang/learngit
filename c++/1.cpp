/*
 * bintmode.c :  此程序计算 (a^power) % mod. power 是大整数
 * 基本公式： (a*b) mod m = ((a mod m) * (b mod m)) mod m
 */
#include<iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;

int modMDyn(int, int ,int);

int main()
{
   cout << modMDyn(451, 151, 15151) << endl;
   cout << modMDyn(modMDyn(451, 151, 15151), 4639, 15151) <<endl;
    
   return 0;
}
/*
 * modMDyn: 使用二进制分解技术求解 (a^power) % mod , power 是个大整数
 */
int modMDyn(int a, int power, int mod)
{
   assert(a>=1 && power >=0 && mod >=1);
   int result = 1;
   int temp = a % mod;
   while (power >= 1) {
      if (power % 2 != 0) {
         result = (result * temp) % mod;   
      }
      temp = (temp * temp) % mod;
      power /= 2;   
   }
   return result;
}