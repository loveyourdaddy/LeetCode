//12ms 
//정진님 감사합니다. 
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;

        //2개의 List를 정의함        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* evenHead = new ListNode();
        ListNode* dummyEvenHead = new ListNode(0);
        dummyEvenHead = evenHead;

        while (head != nullptr && head->next != nullptr)
        {   
            evenHead->next = head->next;
            evenHead = evenHead->next;

            if (head->next->next == nullptr) break;
            head->next = head->next->next;
            head = head->next; 
            
            std::cout << "head:" << head->val << std::endl;
            std::cout << "evenHead:" << evenHead->val << std::endl;
        }
        evenHead->next = nullptr;
        head->next = dummyEvenHead->next;

        return dummyHead->next;
    }
};

int main() {
    Solution sol;

    // ListNode a(1), b(2, &a), c(3, &b), d(4, &c), e(5, &d), f(6, &e);
    ListNode ab(8), aa(7, &ab), a(6, &aa), b(5, &a), c(4, &b), d(3, &c), e(2, &d), f(1, &e);
    ListNode* ans;

    //ListNode (f, nullptr);
            
	ans = sol.oddEvenList(&f);
    
    while (ans)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
    

    return 0; 
}


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
    ListNode* oddEvenList(ListNode* head) {
		if (head == NULL)
			return head;

		// 두개 노드 선언
		ListNode* odd = head;
		ListNode* even = head->next;
		ListNode* evenHead = head->next;

		while (even != NULL && even->next != NULL)
		{
			odd->next = odd->next->next;
			even->next = even->next->next;

			odd = odd->next;
			even = even->next;
		}
		odd->next = evenHead;
		return head;
    }
};

int main() {
    Solution sol;
	ListNode a(5);
	ListNode b(4, &a);
	ListNode c(3, &b);
	ListNode d(2, &c);
	ListNode e(1, &d);

    sol.oddEvenList(&e);
    return 0; 
}

#endif //LETCODE
