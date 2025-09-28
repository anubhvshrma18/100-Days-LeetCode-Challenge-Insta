// Problem Link: https://leetcode.com/problems/group-anagrams/
// Difficulty: Medium
// Time Complexity: O(N * K log K) where N is the number of strings and K is the maximum length of a string
// Space Complexity: O(N * K) for storing the grouped anagrams
// Approach: Use a hash map to group strings by their sorted version


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        
        // Group strings by their sorted version
        for(string& s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(s);
        }
        
        // Convert map to result vector
        vector<vector<string>> result;
        for(auto& pair : map) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};