// 5.最长回文子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution{
public:
	string longestPalindrome(string s)
	{
		if (s.empty()) return "";  //特殊情况1.如果输入的字符串为空，则返回 “”。
		if (s.size() == 1) return s;  //特殊情况2.如果只输入了一个字符，则返回这个字符

		int len = s.size();  // 初始化1.获得字符串的长度
		int start = 0;  // 初始化2.最长回文子串开始的索引
		int maxLength = 1;  // 初始化3.最长回文子串的长度
		int left, right;  // 初始化4.最长回文子串的左右索引

		// 动态规划
		for (unsigned int i = 0; i < len && len - i > maxLength / 2;)  //
		{
			left = right = i;  //第一个回文子串的左右索引为0，是字符串的第一个字符
			// 开始搜索最长回文子串
			while (right < len - 1 && s[right + 1] == s[right]) {  // 右索引小于字符串的长度，且右索引+1的字符 = 右索引的字符  如‘bb’
				++right;   // 那么，最长回文子串的右索引+1
			}
			i = right + 1; //更新i  =》 i+1

			// 中心扩展，s[right + 1] == s[left - 1]  =》 回文的左右首字母相同
			while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) //右索引小于字符串的长度，并且左索引 > 0
			{
				++right;  // 那么，最长回文子串的右索引+1，左索引-1
				--left;
			}
			
			// 更新最长回文子串的长度maxLength， 和 最长回文子串的起始索引
			if (maxLength < right - left + 1)
			{
				start = left;
				maxLength = right - left + 1;
			}
		}
		return s.substr(start, maxLength);  //根据起始索引start 和 字符串的长度maxLength，获得最大回文子串
	}
};
int main()
{
	string s = "acbca";
    cout << Solution().longestPalindrome(s) << endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
