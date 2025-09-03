// Problem Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Time Complexity: O(N)
// Space Complexity: O(1)
// Approach: Two Pointers (First pointer to find kth node from start, Second pointer to find kth node from end)

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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head || !head->next) return head;
        
        ListNode* first = head;
        ListNode* second = head;
        ListNode* kth = nullptr;
        
        // Move first pointer to kth node from beginning
        for (int i = 1; i < k; i++) {
            first = first->next;
        }
        kth = first;
        
        // Move first to end while second moves to kth from end
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        
        // Swap values
        int temp = kth->val;
        kth->val = second->val;
        second->val = temp;
        
        return head;
    }
};