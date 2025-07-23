// LeetCode Problem: Search a node in BST
// Problem Link: https://leetcode.com/problems/search-in-a-binary-search-tree
// Approach: Use recursion to traverse the BST and find the node with the given value
// Time Complexity: O(h) where h is the height of the tree
// Space Complexity: O(h) for the recursion stack

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base cases: if root is null or value is found at root
        if (root == nullptr || root->val == val) {
            return root;
        }
        
        // If value is less than root's value, search in left subtree
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        
        // If value is greater than root's value, search in right subtree
        return searchBST(root->right, val);
    }
};