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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head; 
        int count=0;
        while(p != NULL){
            ++count;
            p = p->next;            
        }
        
        ListNode dummy;
        dummy.next = head;
        
        int idx = 0;        
        int temp;   
        
        while(head->next->next != NULL){
            if(idx+1 == count - n) {
                head->next->val = head->next->next->val;
                head->next = head->next->next;                
                break;
            }        
            head = head->next;                             
            idx++;
            
        }

        return dummy.next;
        
    }
};

