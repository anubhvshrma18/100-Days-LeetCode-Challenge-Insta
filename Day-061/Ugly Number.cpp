// Problem Link: https://leetcode.com/problems/ugly-number/
// Approach: Continuously divide the number by 2, 3, and 5. If the result is 1, it's an ugly number.
// Time Complexity: O(log n) in the worst case
// Space Complexity: O(1)

class Solution {
public:
    bool isUgly(int n) {
        // If number is less than or equal to 0, it's not ugly
        if (n <= 0) return false;
        
        // Divide by 2, 3, and 5 as many times as possible
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        
        // If the number becomes 1, it's ugly
        return n == 1;
    }
};