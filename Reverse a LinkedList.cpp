// Leetcode - 
// Iterative Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head,*prev=NULL,*nex=NULL;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
};
