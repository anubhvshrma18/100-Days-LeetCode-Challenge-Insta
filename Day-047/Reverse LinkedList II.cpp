// LeetCode Problem: Reverse Linked List II
// Problem Link: https://leetcode.com/problems/reverse-linked-list-ii
// Approach: Use a dummy node to simplify edge cases and reverse the sublist in place
// Time Complexity: O(n) where n is the length of the linked list
// Space Complexity: O(1) for the in-place reversal
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        // Move to the position before reversal starts
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        
        // Current node will be the first node to be reversed
        ListNode* curr = prev->next;
        
        // Reverse the sublist
        for (int i = left; i < right; i++) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};