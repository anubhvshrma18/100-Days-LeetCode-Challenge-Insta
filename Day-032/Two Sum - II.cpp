// Problem: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Approach: Two Pointer Technique
// Time Complexity: O(n)
// Space Complexity: O(1)

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1};
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    return {}; // No solution found
}