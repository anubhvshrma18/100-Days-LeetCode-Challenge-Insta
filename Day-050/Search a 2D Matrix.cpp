// LeetCode Problem: Search a 2D Matrix
// Problem Link: https://leetcode.com/problems/search-a-2d-matrix
// Approach: Try going on complete matrix to find the target
// Time Complexity: O(m * n) where m is the number of rows and n is the number of columns
// Space Complexity: O(1) since we are not using any extra space apart from variables

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Simple linear search approach - less optimal than binary search
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Search each element one by one
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
