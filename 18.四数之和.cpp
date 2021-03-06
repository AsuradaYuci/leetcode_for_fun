// 18.四数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4) return {}; //如果数组的元素个数小于4，输出空数组
		sort(nums.begin(), nums.end());  //对数组元素进行重排序，从小到大
		// 构建hash表
		unordered_map<long long, vector<pair<int, int>>> um;

		// 对数组中任意两个数进行相加，获得所有的情况，一共7种，0（3个），-1（2个），1（2个），-2（1个），2（1个），-3（1个），3（1个）
		for (int i = nums.size() - 1; i > 0; --i) {
			if (i < nums.size() - 1 && nums[i] == nums[i + 1])
				continue;
			for (int j = i - 1; j >= 0; --j) {
				if (i - j > 1 && nums[j] == nums[j + 1])
					continue;
				um[nums[i] + nums[j]].push_back({j, i});
			}
		} 
		vector<vector<int>> ret;
		for (unsigned int i = 0; i < nums.size() - 3; ++i) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			for (unsigned int j = i + 1; j < nums.size() - 2; ++j) {
				if (j - i > 1 && nums[j] == nums[j - 1])
					continue;
				long long s = static_cast<long long>(nums[i] + nums[j]);
				auto it = um.find(target - s);
				if (it == um.end())
					continue;
				for (auto p : it->second)
					if (p.first > j)
						ret.push_back({ nums[i],nums[j],nums[p.first],nums[p.second] });
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> s = { 1,0,-1,0,-2,2 };
	int t = 0;
	for (auto& i : Solution().fourSum(s,t)) {
		for (auto& j : i) {
			cout << j << "";
		}
		cout << endl;
	}
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
