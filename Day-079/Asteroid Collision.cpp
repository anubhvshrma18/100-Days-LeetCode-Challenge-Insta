// Problem Link - https://leetcode.com/problems/asteroid-collision/
// Time Complexity: O(N)
// Space Complexity: O(N)
// Approach: Use a stack to simulate the collisions between asteroids. Iterate through the list of asteroids and for each asteroid, check if it collides with the top of the stack. If they collide, determine which one survives or if both are destroyed. Continue this process until all asteroids have been processed.
// If an asteroid survives, push it onto the stack. Finally, return the stack as the result.
// Example: Input: asteroids = [5, 10, -5] Output: [5, 10] Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        
        for (int asteroid : asteroids) {
            bool survived = true;
            
            while (!stack.empty() && asteroid < 0 && stack.back() > 0) {
                if (stack.back() < -asteroid) {
                    stack.pop_back();
                    continue;
                }
                else if (stack.back() == -asteroid) {
                    stack.pop_back();
                }
                survived = false;
                break;
            }
            
            if (survived) {
                stack.push_back(asteroid);
            }
        }
        
        return stack;
    }
};