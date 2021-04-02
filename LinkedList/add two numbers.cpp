// map 함수 : map[key] = val
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        ListNode* ans = dummyHead;
        //ans = dummyHead->next;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            //ans의 next node 생성.  
            ans->next = new ListNode();
            ans = ans->next;

            int currentSum = carry;
            if (l1 != nullptr)
                currentSum += l1->val;
            if (l2 != nullptr)
                currentSum += l2->val;

            carry = currentSum / 10;
            currentSum = currentSum % 10;

            ans->val = currentSum;
            // ans = ans->next;

            l1 = (l1 == nullptr) ? nullptr : l1->next;
            l2 = (l2 == nullptr) ? nullptr : l2->next;
        }

        // 마지막  n ode 생성 : ptr은 null
        if (carry == 1)
            ans->next = new ListNode(carry);
        return dummyHead->next;
    }
};

int main() {
    Solution sol;
    //vector<string> str = { "eat", "tea", "tan", "ate", "nat", "bat" };
    ListNode node1(342, nullptr), node2(465, nullptr), *ans;
        
	ans = sol.addTwoNumbers(&node1, &node2);
    cout << ans->val << endl;

    return 0; 
}
