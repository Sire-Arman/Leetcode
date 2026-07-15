class Solution {
public:
    int gcd(int a, int b){
        return b==0?a:gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int odd = (n*(2*1+(n-1)*2))/2;
        int even = (n*(2*2+(n-1)*2))/2;
        return gcd(odd,even);
    }
};