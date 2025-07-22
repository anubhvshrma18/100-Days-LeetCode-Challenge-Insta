// LeetCode Problem: Kth Missing Positive Number
// Problem Link: https://leetcode.com/problems/kth-missing-positive-number/
// Approach: Use a hash set to track the elements in the array and iterate through positive integers
// until we find the k-th missing positive number.
// Time Complexity: O(n + k)
// Space Complexity: O(n)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Create a hash set to store array elements
        unordered_set<int> numSet;
        for (int num : arr) {
            numSet.insert(num);
        }
        
        // Check each number from 1 until we find kth missing
        int missing = 0;
        int current = 1;
        
        while (missing < k) {
            if (numSet.find(current) == numSet.end()) {
                missing++;
                if (missing == k) {
                    return current;
                }
            }
            current++;
        }
        
        return current;
    }
};