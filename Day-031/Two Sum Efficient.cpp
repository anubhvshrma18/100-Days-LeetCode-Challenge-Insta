// Problem: https://leetcode.com/problems/two-sum/
// Approach: Efficient using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // value -> index
    vector<int> res(2, -1); // Initialize with -1 to indicate no solution found
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_map.count(complement)) {
            res = {num_map[complement], i};
        }
        num_map[nums[i]] = i;
    }
    return res; // No solution found
}