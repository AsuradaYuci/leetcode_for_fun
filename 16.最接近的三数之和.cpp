// 16.最接近的三数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		vector<int> result;
		sort(nums.begin(), nums.end());  //1.对输入数组nums进行排序

		for (unsigned int i = 0; i < nums.size() - 2; ++i) {
			int l = i + 1, r = nums.size() - 1;  //2.按照之前的方法，定义两个指针
			int small = nums[l] + nums[l + 1] + nums[i];  // 从左边连续选择3个数，

			int big = nums[r] + nums[r - 1] + nums[i];  // 选定一个nums[i],从最右边选择两个数
			if (small > target) result.push_back(small);  // 如果small已经大于target，则说明这个small最接近target，输出small
			else if (big < target) result.push_back(big); // 如果big小于target，说明这个big最接近target，输出big
			else {  // 否则，开始遍历中间的数
				while (l < r) {
					// 临时的sum = 选定一个nums[i]，用左右两个指针遍历剩下的数组元素
					int tmp_sum = nums[l] + nums[r] + nums[i];
					result.push_back(tmp_sum);  // 先将这个临时sum，输出
					if (tmp_sum < target) ++l;  //如果临时的sum小于这个target，说明l太小，增加l
					else if (tmp_sum > target)--r; // 如果临时的sum大于这个target，说明r太大，减小r
					else return target;  //如果临时的sum等于这个target，则输出target
				}
			}
		}
		// 对result中的向量进行排序，获得最接近target的元素
		sort(result.begin(), result.end(), [target](const int x1, const int x2) {
			return abs(x1 - target) < abs(x2 - target);
		});
		return result[0];
	}
};

int main()
{
	vector<int> s = { -1,2,1,-4 };
	int target = 1;
	cout << Solution().threeSumClosest(s, target);
	return 0;
}

