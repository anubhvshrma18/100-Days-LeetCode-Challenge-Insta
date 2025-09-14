// Problem Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree
// Difficulty: Medium
// Time Complexity: O(N log N) where N is the number of nodes in the tree
// Space Complexity: O(N)
// Approach: Use DFS to traverse the tree and store nodes in a map based on their vertical and level positions


// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // map<vertical, map<level, multiset<node values>>>
    map<int, map<int, multiset<int>>> nodes;
    
    void dfs(TreeNode* root, int vertical, int level) {
        if (!root) return;
        
        // Add current node to the map
        nodes[vertical][level].insert(root->val);
        
        // Recursively process left and right children
        dfs(root->left, vertical - 1, level + 1);
        dfs(root->right, vertical + 1, level + 1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        nodes.clear();
        dfs(root, 0, 0);
        
        vector<vector<int>> result;
        
        // Process each vertical line
        for (const auto& vertical : nodes) {
            vector<int> col;
            // Process each level in current vertical line
            for (const auto& level : vertical.second) {
                // Add all values at current level to column
                col.insert(col.end(), level.second.begin(), level.second.end());
            }
            result.push_back(col);
        }
        
        return result;
    }
};