// LeetCode Problem: Top K Frequent Elements
// Problem Link: https://leetcode.com/problems/top-k-frequent-elements
// Approach: Use a frequency map to count occurrences and a min-heap to keep track of the top k elements
// Time Complexity: O(n log k) where n is the number of elements in the input array
// Space Complexity: O(n) for the frequency map and O(k) for the min-heap


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create frequency map
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        
        // Create min heap based on frequency
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // Process frequencies
        for(auto it : freq) {
            pq.push({it.second, it.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        // Create result array
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};