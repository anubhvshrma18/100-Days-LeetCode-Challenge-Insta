// LeetCode Problem: Best Time to Buy and Sell Stock
// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Approach: One Pass
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        
        return maxProfit;
    }
};