//反转整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

class Soulution {
public:
	int reverse(int x) {
		int rev = 0;
		while (x != 0)
		{
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX || (rev == INT_MAX / 10 && pop > 7))
			{
				return 0;
			}
			if (rev < INT_MIN || (rev == INT_MIN / 10 && pop < -8))
			{
				return 0;
			}
			rev = rev * 10 + pop;
		}
		return rev;
	}

};

void main() {
	// 对类Solution创建一个对象
	Soulution temp;
	int x = 123456;
	cout << temp.reverse(x) << endl;

}