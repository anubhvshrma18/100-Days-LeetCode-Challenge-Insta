// Problem Link: https://leetcode.com/problems/min-cost-climbing-stairs/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Dynamic Programming

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        
        // Base cases
        dp[0] = 0;  // Starting from before first step
        dp[1] = 0;  // Starting from before second step
        
        // Fill dp array
        for(int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        
        return dp[n];
    }
};