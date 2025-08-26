// Problem Link: https://leetcode.com/problems/contiguous-array/
// Approach: Use a hash map to store the first occurrence of each count of 1s and 0s
// Time Complexity: O(n) where n is the length of the array
// Space Complexity: O(n) for the hash map


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int count = 0;
        unordered_map<int, int> countMap;
        
        // Initialize the map with count 0 at index -1
        countMap[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            // Increment count for 1, decrement for 0
            count += nums[i] == 1 ? 1 : -1;
            
            // If count exists in map, update maxLength
            if (countMap.find(count) != countMap.end()) {
                maxLength = max(maxLength, i - countMap[count]);
            } else {
                // Store first occurrence of this count
                countMap[count] = i;
            }
        }
        
        return maxLength;
    }
};