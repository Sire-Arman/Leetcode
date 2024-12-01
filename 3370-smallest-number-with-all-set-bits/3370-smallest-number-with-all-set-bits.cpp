class Solution {
public:
    int smallestNumber(int n) {
        int bits =0;
        while(n){
            n/=2;
            bits++;
        }
        return pow(2,bits)-1;
    }
};