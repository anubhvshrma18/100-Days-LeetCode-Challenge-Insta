// Problem Link: https://leetcode.com/problems/spiral-matrix/
// Time Complexity: O(M*N) where M is number of rows and N is number of columns in the matrix
// Space Complexity: O(1) ignoring the output array
// Approach: Use four pointers to keep track of the boundaries of the matrix and traverse in a spiral order.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        
        int rowStart = 0, rowEnd = matrix.size()-1;
        int colStart = 0, colEnd = matrix[0].size()-1;
        
        while (rowStart <= rowEnd && colStart <= colEnd) {
            // Traverse right
            for (int j = colStart; j <= colEnd; j++) {
                result.push_back(matrix[rowStart][j]);
            }
            rowStart++;
            
            // Traverse down
            for (int i = rowStart; i <= rowEnd; i++) {
                result.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            
            if (rowStart <= rowEnd) {
                // Traverse left
                for (int j = colEnd; j >= colStart; j--) {
                    result.push_back(matrix[rowEnd][j]);
                }
            }
            rowEnd--;
            
            if (colStart <= colEnd) {
                // Traverse up
                for (int i = rowEnd; i >= rowStart; i--) {
                    result.push_back(matrix[i][colStart]);
                }
            }
            colStart++;
        }
        
        return result;
    }
};