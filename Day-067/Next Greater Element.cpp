// Problem Link: https://leetcode.com/problems/next-greater-element-i/
// Approach: Use a stack to keep track of the next greater elements in nums2 and a hash map to store the results
// Time Complexity: O(n + m) where n is the length of nums2 and m is the length of nums1
// Space Complexity: O(n) for the stack and hash map

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nextGreater;
        vector<int> result;
        
        // Find next greater element for each element in nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                nextGreater[nums2[i]] = -1;
            } else {
                nextGreater[nums2[i]] = st.top();
            }
            
            st.push(nums2[i]);
        }
        
        // Find corresponding next greater elements for nums1
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        
        return result;
    }
};