// Problem: https://leetcode.com/problems/first-missing-positive/
// Approach: Boyer-Moore Voting Algorithm
// Time Complexity: O(N)
// Space Complexity: O(1)

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}