// Problem Link: https://leetcode.com/problems/next-permutation/
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Find the first decreasing element from the right.
// If found, find the number just larger than it to swap with.
// Finally, reverse the subarray after the position of the first decreasing element.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Find first decreasing element from right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            // Find number just larger than nums[i]
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        
        // Reverse the subarray after position i
        reverse(nums.begin() + i + 1, nums.end());
    }
    
private:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};