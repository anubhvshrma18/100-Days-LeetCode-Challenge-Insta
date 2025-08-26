// Problem Link: https://leetcode.com/problems/roman-to-integer/
// Approach: Use a hash map to store the values of Roman numerals and iterate through the string
// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1) since the hash map size is constant

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // If current value is less than next value, subtract current value
            if (i + 1 < s.length() && romanValues[s[i]] < romanValues[s[i + 1]]) {
                result -= romanValues[s[i]];
            } else {
                result += romanValues[s[i]];
            }
        }
        
        return result;
    }
};