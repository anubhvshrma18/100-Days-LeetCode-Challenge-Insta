// Problem: 3Sum Closest
// Problem Link: https://leetcode.com/problems/3sum-closest
// Approach: Sort the array and use a two-pointer technique to find the closest sum
// Time Complexity: O(n^2) where n is the number of elements in the array
// Space Complexity: O(1) if we ignore the space used for sorting

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                if (currentSum == target) {
                    return currentSum;
                }
                
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return closestSum;
    }
};