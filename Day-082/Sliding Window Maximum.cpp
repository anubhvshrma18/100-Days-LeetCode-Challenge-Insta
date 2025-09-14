// Problem Link: https://leetcode.com/problems/sliding-window-maximum/
// Difficulty: Hard
// Time Complexity: O(n)
// Space Complexity: O(k)


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // stores indices
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements outside current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Remove elements smaller than current element from back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            // Start storing results after first k-1 elements
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};