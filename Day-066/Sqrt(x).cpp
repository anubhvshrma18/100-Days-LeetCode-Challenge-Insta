// Problem Link: https://leetcode.com/problems/sqrtx/
// Approach: Use binary search to find the integer square root
// Time Complexity: O(log x) where x is the input number
// Space Complexity: O(1) for the binary search

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        long long left = 1;
        long long right = x;
        
        // Binary search to find square root
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (mid * mid == x) {
                return mid;
            }
            
            if (mid * mid < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return right;
    }
};