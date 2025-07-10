// This code implements a Dutch National Flag problem solution to sort an array of 0s, 1s, and 2s.
// LeetCode Problem: https://leetcode.com/problems/sort-colors/
// Problem: Given an array with n objects colored red, white, or blue, sort them
// in-place so that objects of the same color are adjacent, with the colors in the order
// red, white, and blue. Here, we will use 0 for red, 1 for white, and 2 for blue.
// Approach: Use three pointers (low, mid, high) to partition the array into three sections.
// - low: points to the next position for 0 (red)
// - mid: current element being examined
// - high: points to the next position for 2 (blue)
// Time Complexity: O(n)
// Space Complexity: O(1)
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low++], nums[mid++]);
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high--]);
        }
    }
}