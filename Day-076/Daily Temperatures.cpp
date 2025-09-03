// Problem Link: https://leetcode.com/problems/daily-temperatures/
// Time Complexity: O(N)
// Space Complexity: O(N)
// Approach: Use a stack to keep track of indices of days with unresolved temperatures.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; // stack to store indices
        
        for (int i = 0; i < n; i++) {
            // While stack is not empty and current temperature is greater than temperature at stack top
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();
                result[prevDay] = i - prevDay; // Calculate days difference
            }
            st.push(i); // Push current day's index
        }
        
        return result;
    }
};