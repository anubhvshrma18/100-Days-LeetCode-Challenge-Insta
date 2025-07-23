// LeetCode Problem: Product of Array Except Self
// Problem Link: https://leetcode.com/problems/product-of-array-except-self
// Approach: Use two passes to calculate prefix and suffix products
// Time Complexity: O(n)
// Space Complexity: O(1) for the result array (excluding input and output)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Calculate prefix products
        int prefix = 1;
        for(int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        
        // Calculate suffix products and combine
        int suffix = 1;
        for(int i = n-1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        
        return result;
    }
};