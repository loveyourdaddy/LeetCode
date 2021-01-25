//https://leetcode.com/problems/add-two-numbers/solution/
//singly-linked list : https://xtar.tistory.com/33
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // pListNode는 list node의 어떤 node인지를 알려주는 pointer
// & : 주소값
// * : 포인터의 객체 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL; 
        int sum = 0;
        ListNode** pListNode = &l3;
        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            *pListNode = new ListNode(sum%10);          
            sum /= 10;
            pListNode = &((*pListNode)->next);
        }
        
        return l3;
    }
};
