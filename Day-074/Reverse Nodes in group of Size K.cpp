// Problem Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Time Complexity: O(N)
// Space Complexity: O(1)
// Approach: Two Pointer Technique to find the kth node from start and end and swap their values.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        
        // Count the length of linked list
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        
        // Create dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        curr = head;
        
        while (count >= k) {
            ListNode* first = curr;
            ListNode* tail = prev;
            
            // Reverse k nodes
            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            // Connect with rest of the list
            tail->next = prev;
            first->next = curr;
            prev = first;
            
            count -= k;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};