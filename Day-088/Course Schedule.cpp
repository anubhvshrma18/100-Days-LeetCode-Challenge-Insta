// Problem Link: https://leetcode.com/problems/course-schedule/
// Time Complexity: O(V + E) where V is the number of courses and E is the number of prerequisites
// Space Complexity: O(V + E) for the adjacency list and indegree array
// Approach: Kahn's Algorithm (BFS for Topological Sorting)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build adjacency list and calculate indegree
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        // Add all nodes with 0 indegree to queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        // Process queue
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;
            
            // Reduce indegree for all adjacent nodes
            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        // If we can visit all nodes, no cycle exists
        return count == numCourses;
    }
};