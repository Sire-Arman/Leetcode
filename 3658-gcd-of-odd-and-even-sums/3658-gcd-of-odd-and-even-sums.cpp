class Solution {
public:
    int gcd(int a, int b){
        return b==0?a:gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int i =1,odd=0,even=0;
        while(n--){
            odd +=i;
            i++;
            even+=i;
            i++;
        }
        return gcd(odd,even);
    }
};