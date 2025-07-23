// LeetCode Problem: Letter Combinations of a Phone Number
// Problem Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number
// Approach: Use backtracking to generate all possible letter combinations based on the phone number mapping
// Time Complexity: O(3^n * 4^m) where n is the number of digits that map to 3 letters and m is the number of digits that map to 4 letters
// Space Complexity: O(n) for the recursion stack and result storage

class Solution {
private:
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void backtrack(string digits, int index, string current, vector<string>& result) {
        if (index == digits.length()) {
            if (!current.empty()) {
                result.push_back(current);
            }
            return;
        }
        
        string letters = keypad[digits[index] - '0'];
        for (char letter : letters) {
            backtrack(digits, index + 1, current + letter, result);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        backtrack(digits, 0, "", result);
        return result;
    }
};