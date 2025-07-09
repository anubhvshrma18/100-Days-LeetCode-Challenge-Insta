// LeetCode Problem: 724. Find Pivot Index
// Problem: Given an array of integers nums, return the pivot index of the array. If
// the pivot index is the index where the sum of all the numbers to the left of the
// index is equal to the sum of all the numbers to the right of the index. If no such index exists, return -1.
// Approach: Calculate the total sum of the array and iterate through the array while maintaining a left sum. For each index, check if the left sum equals the
// total sum minus the left sum minus the current element. If it does, return the index.
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0, leftSum = 0;
        for (int num : nums) total += num;
        for (int i = 0; i < nums.size(); ++i) {
            if (leftSum == total - leftSum - nums[i]) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};