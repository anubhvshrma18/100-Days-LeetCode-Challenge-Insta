// Problem: Find Peak Element
// Problem Link: https://leetcode.com/problems/find-peak-element
// Approach: Use binary search to efficiently find a peak element
// Time Complexity: O(log n) where n is the length of the input array
// Space Complexity: O(1) for the binary search

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        // Binary search to find peak element
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If middle element is less than next element,
            // then peak must be in right half
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } 
            // Otherwise, peak must be in left half including mid
            else {
                right = mid;
            }
        }
        
        return left; // At this point, left == right and points to peak
    }
};