// Space Complexity: O(N)
// Time Complexity: O(N)
// Problem Link: https://leetcode.com/problems/first-missing-positive/

int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> s;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]>0){
            s.insert(nums[i]);
        }
    }
    int smallestPositive = 1;

    while (s.find(smallestPositive) != s.end()) {
        smallestPositive++;
    }

    return smallestPositive;
}