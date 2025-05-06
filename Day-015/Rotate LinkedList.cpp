class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head,*prev=nullptr,*ne=nullptr;
        while(curr!=nullptr){
            ne=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ne;
        }
        return prev;
    }
    ListNode* rotateLL(ListNode* head) {
        ListNode* temp=head;
        while(temp->next!=NULL) {
            temp=temp->next;
        }
        ListNode* tail=temp;
        temp=head;
        tail->next=temp;
        head=head->next;
        temp->next=NULL;
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head || !head->next)
            return head;
        int n = 0;
        ListNode* temp=head;
        while(temp!=NULL) {
            n++;
            temp=temp->next;
        }
        k=k%n;
        head=reverseList(head);
        for(int i=0;i<k;i++) {
            head=rotateLL(head);
        }
        return reverseList(head);
    }
};
