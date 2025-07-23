// LeetCode Problem: Contains Duplicate
// Problem Link: https://leetcode.com/problems/contains-duplicate
// Approach: Use a hash set to track seen elements and check for duplicates
// Time Complexity: O(n) where n is the number of elements in the input array
// Space Complexity: O(n) for the hash set

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.count(num) > 0) {
                return true;
            }
            seen.insert(num);
        }
        
        return false;
    }
};