// Problem: Reverse Words in a String
// Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Approach: Two-pointer technique to reverse the entire string and then each word individually
// Time Complexity: O(n)
// Space Complexity: O(1) (if we ignore the space used for the output string

class Solution {
public:
    string reverseWords(string s) {
        // Remove extra spaces and trim
        string cleaned;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ' || (cleaned.length() > 0 && cleaned.back() != ' ')) {
                cleaned += s[i];
            }
        }
        if (cleaned.back() == ' ') cleaned.pop_back();
        if (cleaned.empty()) return "";

        // Reverse the entire string
        reverse(cleaned.begin(), cleaned.end());

        // Reverse individual words
        int start = 0;
        for (int i = 0; i <= cleaned.length(); i++) {
            if (i == cleaned.length() || cleaned[i] == ' ') {
                reverse(cleaned.begin() + start, cleaned.begin() + i);
                start = i + 1;
            }
        }

        return cleaned;
    }
};