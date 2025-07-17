// LeetCode Problem: Trapping Rain Water
// Problem: https://leetcode.com/problems/trapping-rain-water/
// Approach: Two Pointer Technique 
// Time Complexity: O(n)
// Space Complexity: O(1)

public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int result = 0;
        
        while (left < right) {
            // Update maximum height from left
            leftMax = max(leftMax, height[left]);
            // Update maximum height from right
            rightMax = max(rightMax, height[right]);
            
            // If left wall is smaller than right wall
            if (height[left] < height[right]) {
                // Water trapped at current position = leftMax - current height
                result += leftMax - height[left];
                left++;
            }
            // If right wall is smaller or equal to left wall
            else {
                // Water trapped at current position = rightMax - current height
                result += rightMax - height[right];
                right--;
            }
        }
        
        return result;
    }
};