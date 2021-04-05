// 에
ListNode* oddEvenList(ListNode* head) {
        //2개의 List를 정의함        
        ListNode* evenHead = head; 
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next= head;

        while (head->next != nullptr) 
        {
            std::cout<< head->val <<std::endl;

            evenHead = head->next;
            //evenHead = evenHead->next;
            //head->next = head->next->next;
            head = head->next;
        }
        
        head->next = evenHead;
        return dummyHead->next;
    }
