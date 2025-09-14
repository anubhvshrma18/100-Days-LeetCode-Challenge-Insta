// Problem Link: https://leetcode.com/problems/contains-duplicate-ii/
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Using HashMap to store the last seen index of each number and checking the distance condition. 
// If a duplicate is found within the distance k, return true.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map; // stores number and its last seen index
        
        for (int i = 0; i < nums.size(); i++) {
            // If number exists in map and distance is <= k
            if (map.count(nums[i]) && i - map[nums[i]] <= k) {
                return true;
            }
            // Update the last position of current number
            map[nums[i]] = i;
        }
        return false;
    }
};