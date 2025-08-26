// Problem Link: https://leetcode.com/problems/3sum/
// Approach: Sort the array and use two pointers to find pairs that sum to the negative of the current element
// Time Complexity: O(n^2) where n is the number of elements in the array
// Space Complexity: O(1) if we don't count the output space


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        
        // Sort the array first
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // Skip duplicates for right
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        
        return result;
    }
};