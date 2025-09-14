// Problem Link: https://leetcode.com/problems/01-matrix/
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
// Approach: Multi-source BFS
// We start BFS from all 0s in the matrix and update the distance for each 1 we encounter.
// This ensures that we find the shortest distance to a 0 for each cell.
// We use a queue to facilitate the BFS and a distance matrix to keep track of the distances.
// We initialize the distance for 0s to 0 and for 1s to a large value (INT_MAX - 10000 to avoid overflow).
// We then process each cell in the queue, checking its 4 adjacent cells (up, down, left, right).
// If we find a cell with a distance greater than the current cell's distance + 1, we update it and add it to the queue for further processing.
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX - 10000));
        queue<pair<int, int>> q;
        
        // First pass: Find all 0s and add them to queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Directions for adjacent cells
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // BFS to process cells
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // Check all 4 adjacent cells
            for(auto dir : dirs) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                
                // If new position is valid and we can get a shorter distance
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                   dist[newRow][newCol] > dist[row][col] + 1) {
                    dist[newRow][newCol] = dist[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        
        return dist;
    }
};