#include "pch.h"
#include <iostream>
using namespace std;

//定义一个链表节点，每个结点都包含一个数字，并且数字按位逆序存储。
struct ListNode {
	int val;  //这个节点的值
	ListNode *next;  //指向下一个节点
	ListNode(int x) : val(x), next(NULL){}
};

//就像在纸上计算两个数字的和，先从最低有效位（链表l1和l2的表头）开始相加。每位数字的范围为0~9，求和时，存在进位情况。
//当存在进位情况时，（如5+7=12），在当前位保留2，将进位1带入下一次的迭代中。进位只能是0或1.
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result = new ListNode(0);  //新建一个结果链表节点，存放求和结果，val初始化为0.
		ListNode* tmp = result;  //临时链表节点，用来存放进位值0或1
		int sum = 0;  //使用变量sum来跟踪进位
		while (l1 || l2) {  //l1或l2链表节点的值不全为null，则进行while循环。
			if (l1) {   //如果l1链表节点的值不为null，说明这个链表还没遍历结束，进行遍历
				sum += l1->val;
				l1 = l1->next;  //指向下一个链表节点
			}
			if (l2) { //如果l2链表节点的值不为null，说明这个链表还没遍历结束，进行遍历
				sum += l2->val;
				l2 = l2->next;  //指向下一个链表节点
			}
			// 相当于sum = l1->val + l2->val
			tmp->next = new ListNode(sum % 10);  // sum % 10 取余，确保每一位数在0~9之间。
			sum /= 10;  // 整除，sum >= 10,则进位sum = 1，否则sum = 0
			tmp = tmp->next; // 存放当前位结果  ==》   result = new ListNode(sum % 10)
		}
		if (sum) //如果l1和l2链表节点都遍历结束了，但进位sum不为0
			tmp->next = new ListNode(1);  // 新建一个链表节点，其值初始化为1
		return result->next; //更新result

	}

};

int main() {
	//初始化第一个节点，输入342
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	//初始化第二个节点，输入465
	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	//获得结果  342 + 465 = 807
	ListNode* result = Solution().addTwoNumbers(l1, l2);
	//输出结果 807
	while (result != NULL) {
		cout << result->val << endl;
		result = result->next;
	}

}