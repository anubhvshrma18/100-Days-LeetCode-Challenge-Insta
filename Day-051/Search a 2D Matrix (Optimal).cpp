// LeetCode Problem: Search a 2D Matrix
// Problem Link: https://leetcode.com/problems/search-a-2d-matrix
// Approach: Use binary search to find the target in a flattened version of the matrix
// Time Complexity: O(log(m * n)) where m is the number of rows and n is the number of columns
// Space Complexity: O(1) since we are not using any extra space apart from variables

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        
        // Perform binary search on the matrix as if it were a 1D sorted array
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;
            
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
