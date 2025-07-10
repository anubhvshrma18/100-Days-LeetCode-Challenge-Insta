// Leetcode Problem: https://leetcode.com/problems/sort-colors/
// Problem: Given an array with n objects colored red, white, or blue, sort them
// in-place so that objects of the same color are adjacent, with the colors in the order
// red, white, and blue. Here, we will use 0 for red, 1 for white, and 2 for blue.
// Approach: Counting Sort
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0, 0, 0};
        // Count occurrences of 0, 1, and 2
        for (int num : nums) {
            count[num]++;
        }
        // Overwrite nums with the correct number of 0s, 1s, and 2s
        int idx = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                nums[idx++] = i;
            }
        }
    }
};