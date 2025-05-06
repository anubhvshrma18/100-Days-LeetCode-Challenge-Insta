// LeetCode - https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = 0;
        for(int candy:candies) {
            if(candy > maxCandy){
                maxCandy = candy;
            }
        }
        vector<bool> res(candies.size());
        for(int i=0;i<candies.size();i++) {
            res[i] = (candies[i] + extraCandies >= maxCandy) ? true : false;
        }
        return res;
    }
};
