/**
LeetCode Problem: 237. Delete Node in a Linked List
https://leetcode.com/problems/delete-node-in-a-linked-list/
Problem: Write a function to delete a node in a singly linked list, given only access to that node.
 The node to be deleted is guaranteed to not be the last node in the list.
 Approach: Copy the value from the next node to the current node and then bypass the next node by linking the current node to the node after the next one.
 Finally, delete the next node to free up memory.
 Time Complexity: O(1) - since we are only modifying pointers and values of the nodes, not traversing the list.
 Space Complexity: O(1) - no additional space is used apart from a few pointers.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value from the next node
        node->val = node->next->val;
        // Bypass the next node
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};