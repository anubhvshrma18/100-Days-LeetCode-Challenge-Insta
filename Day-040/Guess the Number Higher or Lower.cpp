// LeetCode Problem: Guess the Number Higher or Lower
// Problem Link: https://leetcode.com/problems/guess-number-higher-or-lower/
// This code implements a binary search algorithm to guess a number
// between 1 and n, where the guess API is provided to compare the guessed number.
// // Time Complexity: O(log n)
// // Space Complexity: O(1)

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than picked number
 *                1 if num is lower than picked number
 *                0 if num is equal to picked number
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoid overflow
            int result = guess(mid);
            
            if (result == 0) {
                return mid;
            } else if (result == -1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};