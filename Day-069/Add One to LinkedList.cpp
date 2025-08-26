// Problem: Add One to Linked List
// Problem Link: https://leetcode.com/problems/add-one-to-linked-list
// Approach: Reverse the linked list, add one, handle carry, and reverse back
// Time Complexity: O(n) where n is the length of the linked list
// Space Complexity: O(1) for in-place operations

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Helper function to reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* addOne(ListNode* head) {
        if (head == NULL) return new ListNode(1);
        
        // Reverse the linked list
        head = reverse(head);
        
        // Add one to first node
        ListNode* curr = head;
        int carry = 1;
        
        while (curr != NULL && carry > 0) {
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;
            
            // If carry exists but we're at last node
            if (carry > 0 && curr->next == NULL) {
                curr->next = new ListNode(carry);
                break;
            }
            curr = curr->next;
        }
        
        // Reverse back the linked list
        return reverse(head);
    }
};