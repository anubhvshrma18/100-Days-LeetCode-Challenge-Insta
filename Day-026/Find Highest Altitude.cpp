// LeetCode Problem: 1732. Find the Highest Altitude
// Problem: There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude 0. You are given an integer array gain of length n where gain[i] is the net
// gain in altitude between points i and i + 1 for all (0 <= i < n). Return the highest altitude of a point.
// Approach: Iterate through the gain array, maintaining the current altitude and updating the maximum altitude encountered.
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0, currAlt = 0;
        for (int g : gain) {
            currAlt += g;
            maxAlt = max(maxAlt, currAlt);
        }
        return maxAlt;
    }
};