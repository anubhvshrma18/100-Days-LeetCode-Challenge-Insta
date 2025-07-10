// Problem: https://leetcode.com/problems/next-greater-node-in-linked-list/
// Given a linked list, return an array of the next greater node values for each node.
// If there is no next greater node, the value should be 0.
// Approach: Use a stack to keep track of indices of nodes whose next greater node has not been found yet.
// Traverse the linked list, and for each node, check if it is greater than the node at the index stored at the top of the stack.
// If it is, pop the index from the stack and set the result for that index to the current node's value.
// Continue this until the stack is empty or the current node's value is not greater than the value at the index stored at the top of the stack.
// Finally, push the current index onto the stack.
// Time Complexity: O(n) - each node is pushed and popped from the stack at most once.
// Space Complexity: O(n) - for the stack and the result array.

class Solution {
public:
    std::vector<int> nextLargerNodes(ListNode* head) {
        std::vector<int> values;
        for (ListNode* curr = head; curr; curr = curr->next) {
            values.push_back(curr->val);
        }
        std::vector<int> res(values.size(), 0);
        std::stack<int> st; // stores indices

        for (int i = 0; i < values.size(); ++i) {
            while (!st.empty() && values[i] > values[st.top()]) {
                res[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};