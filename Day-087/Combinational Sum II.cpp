// Problem Link: https://leetcode.com/problems/combination-sum-ii/
// Difficulty: Medium
// Time Complexity: O(2^n)
// Space Complexity: O(n)
// Approach: Backtracking

class Solution {
public:
    void findCombinations(vector<int>& candidates, int target, vector<vector<int>>& result,
                         vector<int>& current, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
            // Skip duplicates to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i-1]) continue;
            
            current.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], result, current, i + 1);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(candidates, target, result, current, 0);
        return result;
    }
};