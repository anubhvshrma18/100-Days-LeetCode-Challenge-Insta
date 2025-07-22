// LeetCode Problem: Kth Missing Positive Number
// Problem Link: https://leetcode.com/problems/kth-missing-positive-number/
// Approach: Use binary search to find the position where the number of missing positive integers exceeds k
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        
        // Binary search to find the position where missing numbers exceed k
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Return kth missing number
        return left + k;
    }
};
