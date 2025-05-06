class Solution {
    public:
        string gcdOfStrings(string str1, string str2) {
            if(str1+str2 == str2+str1) {
                int gcd = getGCD(str1.length(), str2.length());
                return str1.substr(0,gcd);
            } else {
                return "";
            }
        }
        
        int getGCD(int a, int b) {
            while(b%a != 0) {
                int temp = b%a;
                b = a;
                a = temp;
            }
            return a;
        }
    };