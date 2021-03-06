// 15.三数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;  //存储返回的结果
		int nums_len = nums.size();  //获得输入数组的长度
		int left, right, dif;
		sort(nums.begin(), nums.end()); //1.对数组元素进行排序，非降序 = 升序

		for (int i = 0; i < nums_len - 2; i++) {
			// 2.如果排完序后的数组的第一个元素大于0；则返回
			if (nums[i] > 0)break;
			// 3.如果前后两个元素大小一致，则继续下一个循环；  
			if (i > 0 && nums[i - 1] == nums[i])continue;
			left = i + 1;
			right = nums_len - 1;//数组的最右边元素
			dif = -nums[i];  //将排序后的第i个取反，这样三数之和为0 = （两数之和 = 第三个数的负数）

			// 4.左边的索引 < 右边的索引
			while (left < right) {
				//三数之和 = 0；left + right = dif = -nums[i]
				if(nums[left] + nums[right ]== dif){   // 5.符合题目条件，将三个数输出到result中
					result.push_back({ nums[i],nums[left],nums[right] });
					++left;  // 6.判断left下一个数是否与前一个数一样，如果一样，则更新left，直到不一样，防止出现重复的三元组
					while (left < right&&nums[left - 1] == nums[left]) { ++left; }
					--right; // 7.更新right
				}
				else if (nums[left] + nums[right] < dif) { // 8.不符合输出条件，两数之和 < 0 说明数太小，增加left
					++left;
				}
				else {   // 9.不符合输出条件，两数之和 > 0 说明数太大，减小right
					--right;
				}
			}
		}
		return result;
	}
};

int main()
{
	vector<int> s = { -1,0,1,2,-1,-4 };
	for (auto& i : Solution().threeSum(s)) {
		for (auto& j : i) {
			cout << j << "";
		}
		cout << endl;             
	}
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
