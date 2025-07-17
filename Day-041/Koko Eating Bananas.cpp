// LeetCode Problem: Koko Eating Bananas
// Problem Link: https://leetcode.com/problems/koko-eating-bananas/
// Approach: Binary Search
// Time Complexity: O(n log m), where n is the number of piles and m is the maximum number of bananas in a pile.
// Space Complexity: O(1)


class Solution {
public:
    bool canEatAll(vector<int>& piles, int k, int h) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // ceiling division
        }
        return hours <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEatAll(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};