// Question - https://leetcode.com/problems/can-place-flowers/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i=0;i<flowerbed.size();i++) {
            if(flowerbed[i] == 0) {
                // find the next pos value and previous pos value
                int prev = (i==0) ? 0 : flowerbed[i-1];
                int next = (i==flowerbed.size()-1) ? 0 : flowerbed[i+1];
                if(prev == 0 && next == 0) {
                    flowerbed[i]=1;
                    count++;
                }
            }
        }
        return (count >= n);
    }
};
