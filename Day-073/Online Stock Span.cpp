// Problem Link: https://leetcode.com/problems/online-stock-span/
// Time Complexity: O(N) for N calls to next()
// Space Complexity: O(N)
// Approach: Use a stack to keep track of prices and their spans. For each new price, pop from the stack while the top price is less than or equal to the current price, accumulating the spans. Push the current price and its span onto the stack.

class StockSpanner {
private:
    stack<pair<int, int>> st; // price, span pair
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        
        // Pop elements from stack while they're less than or equal to current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        // Push current price and its span
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */