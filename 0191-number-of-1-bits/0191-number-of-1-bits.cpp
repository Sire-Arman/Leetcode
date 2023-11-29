class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            int rem = n%2;
            n/=2;
            if(rem ==1){
                cnt++;
            }
        }
        return cnt;
    }
};