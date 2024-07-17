// Leetcode - https://leetcode.com/problems/odd-even-linked-list
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        ListNode* odd=head, *even=head->next;
        ListNode* evenHead=even; // to remembrer the even head
        while(even!=NULL && even->next != NULL) {
            odd->next=odd->next->next;
            even->next=even->next->next;
            
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};
