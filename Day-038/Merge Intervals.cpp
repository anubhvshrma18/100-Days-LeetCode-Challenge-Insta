// LeetCode Link: https://leetcode.com/problems/merge-intervals/
// Problem: Merge Intervals
// Approach: Sorting and Merging
// Time Complexity: O(n log n) for sorting, O(n) for merging
// Space Complexity: O(n) for storing the result



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If intervals array is empty, return empty result
        if (intervals.empty()) return {};
        
        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            // If current interval overlaps with the last result interval
            if (result.back()[1] >= intervals[i][0]) {
                // Merge them by updating the end time of last result interval
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // If no overlap, add current interval to result
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};