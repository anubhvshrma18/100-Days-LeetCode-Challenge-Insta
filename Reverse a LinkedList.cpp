// Leetcode - https://leetcode.com/problems/reverse-linked-list/
// Iterative Solution 
// Time Complexity - O(N)
// Space Complexity - O(1)
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
