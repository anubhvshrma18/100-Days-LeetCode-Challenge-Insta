// Problem: https://leetcode.com/problems/first-missing-positive/
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    
    // Step 1: Replace negative numbers and zeros with n+1
    for (int i = 0; i < n; i++) {
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = n + 1;
        }
    }
    
    // Step 2: Mark the presence of numbers in the range [1, n]
    for (int i = 0; i < n; i++) {
        int num = abs(nums[i]);
        if (num <= n) {
            nums[num - 1] = -abs(nums[num - 1]);
        }
    }
    
    // Step 3: Find the first missing positive
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }
    
    return n + 1;
}
