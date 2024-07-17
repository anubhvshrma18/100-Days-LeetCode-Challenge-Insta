// Leetcode - https://leetcode.com/problems/palindrome-linked-list
class Solution {
public:
    ListNode* findMid(ListNode* head) {
        ListNode* slow=head, *fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverseLL(ListNode* head) {
        ListNode* curr=head, *prev=NULL, *next=NULL;
        while(curr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* mid=findMid(head);
        ListNode* rev=reverseLL(mid);
        ListNode* temp = head;
        while(temp && rev) {
            if(temp->val != rev->val) return false;
            temp=temp->next;
            rev=rev->next;
        }
        return true;
    }
};
