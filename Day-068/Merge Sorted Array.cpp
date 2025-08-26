// Problem Link: https://leetcode.com/problems/merge-sorted-array/
// Approach: Use three pointers to merge the two arrays from the end to avoid overwriting elements
// Time Complexity: O(m + n) where m and n are the lengths of nums1 and nums2
// Space Complexity: O(1) since we are merging in place

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;    // Index for nums1
        int j = n - 1;    // Index for nums2
        int k = m + n - 1; // Index for merged array
        
        // Start from the end and merge in descending order
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};