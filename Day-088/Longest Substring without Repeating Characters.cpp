// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Sliding Window with HashMap


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1); // Track last position of each character
        int maxLength = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            // If character is already seen after start, update start
            if (lastSeen[s[end]] >= start) {
                start = lastSeen[s[end]] + 1;
            }
            
            lastSeen[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};