#ifndef LEETCODE
#define LEETCODE

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <math.h>
#include <deque>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		// 런너로 전체 길이 찾기 
		ListNode* half = nullptr;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			half = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		half->next = nullptr;

		ListNode* left = sortList(head);
		ListNode* right = sortList(slow);

		ListNode* tmp = mergeSortList(left, right);
		return tmp;
    }
	ListNode* mergeSortList(ListNode* l1, ListNode* l2)
	{
		ListNode* dummy = new ListNode(0); // pointing first of listNode
		ListNode* head = dummy;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val < l2->val)
			{
				head->next = l1;
				l1 = l1->next;
			}
			else
			{
				head->next = l2;
				l2 = l2->next;
			}
			head = head->next;
		}
		// 남은걸 뒤에 붙여줌 
		if (l1 != nullptr) head->next = l1;
		if (l2 != nullptr) head->next = l2;
		return dummy->next;
	}
};

int main() {
    Solution sol;
	ListNode b(3);
	ListNode c(1, &b);
	ListNode d(2, &c);
	ListNode e(4, &d);

    ListNode* ans = sol.sortList(&e);
    return 0; 
}

#endif //LETCODE
