// Problem Link: https://leetcode.com/problems/container-with-most-water/
// Time Complexity: O(N)
// Space Complexity: O(1)
// Approach: Two Pointer Technique to find the maximum area by moving the pointers based on the heights

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Calculate width between two lines
            int width = right - left;
            // Height is minimum of two lines
            int h = min(height[left], height[right]);
            // Calculate area
            int area = width * h;
            // Update maximum area if current area is larger
            maxWater = max(maxWater, area);
            
            // Move the pointer with smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};