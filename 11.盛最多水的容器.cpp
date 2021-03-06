// 11.盛最多水的容器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxarea = 0;
		int area;
		int l = 0;
		int r = height.size() - 1;

		while (l < r) {
			area = min(height[l], height[r])*(r - l);
			maxarea = max(maxarea, area);
			if (height[l] < height[r]) {
				l++;
			}
			else {
				r--;
			}
		}
		return maxarea;
	}
};
int main()
{
	vector<int> h = {1,2,1};
	cout << Solution().maxArea(h) << endl;
	return 0;
}