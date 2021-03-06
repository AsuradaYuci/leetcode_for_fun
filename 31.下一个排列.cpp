// 31.下一个排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 1;//初始化最右边的索引
		int j = i; 
		//1.从右往左找，第一个左邻小于右邻的数（升序）。降序数组没有下一个排列
		while (i >= 0 && nums[i] <= nums[i-1]) {
			i--; 
		}
		--i; //2.记左邻所在位置为i
		if (i >= 0) {
			//3.从右往左，找到第一个比左邻大的数，记为j
			while (j >= 0 && nums[j] <= nums[i]) {
				j--;
			}
			//4.将i与j所在元素交换
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
		// 5.将i+1至最后一个元素从小到大排序，得到所要求的下一个排列
		++i;
		reverse(nums.begin() + i, nums.end()); //6.逆序（反转）[first,last)范围内的顺序
	}
};

int main()
{
	vector<int> s = { 1,2,3 };
    Solution().nextPermutation(s);
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
