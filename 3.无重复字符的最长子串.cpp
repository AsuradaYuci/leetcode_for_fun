// 3.无重复字符的最长子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// leetcode 玄学加速代码
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int size = s.size(); //获得输入字符串的长度
		vector<int> dict(256, -1); //初始化一个向量dict，包括256个值为-1的int类型元素。
		int start = -1;  //表示遍历到str[i]时，以str[i-1]字符为结尾的情况下，最长无重复子串开始的前一个位置。
		int maxLength = 0;  //记录以每个字符结尾的情况下，最长无重复子串长度的最大值。
		// dict[s[i]]表示遍历完s[0] - s[i-1]后，s[i]字符最近一次出现的位置，可以记为A。
		//start + 1 表示，以str[i-1]字符结尾的情况下，最长无重复子串的开始位置
	
		for (int i = 0; i < size; i++) {
			if (dict[s[i]] > start) {
				start = dict[s[i]];
			}
			dict[s[i]] = i;
			/*讨论：
			A = dict[s[i]] > start;  以str[i]结尾的最长无重复子串的范围为：s[A+1] ~ s[i]

			A = dict[s[i]] < start;  以str[i]结尾的最长无重复子串的范围为：s[start+1] ~ s[i]
			*/
			maxLength = max(maxLength, i - start);
		}
		
		return maxLength;
	}
};


int main()
{
	string s = "abcabcbb";
	cout << Solution().lengthOfLongestSubstring(s) << endl;
	return 0;
}
