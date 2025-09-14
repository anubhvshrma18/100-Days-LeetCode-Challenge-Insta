// Problem Link: https://leetcode.com/problems/domino-and-tromino-tiling/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Dynamic Programming
class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n <= 2) return n;
        if (n == 3) return 5;
        
        vector<long long> dp(n + 1);
        dp[1] = 1; // One vertical domino
        dp[2] = 2; // Two horizontal or two vertical dominoes
        dp[3] = 5; // Five different possibilities
        
        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i-1] + dp[i-3]) % MOD;
        }
        
        return dp[n];
    }
};