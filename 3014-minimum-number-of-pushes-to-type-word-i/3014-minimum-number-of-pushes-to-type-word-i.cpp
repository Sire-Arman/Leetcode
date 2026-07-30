class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int cnt = 1,ans=0;
        while(n>=8){
            ans += cnt*8;
            cnt++;
            n-=8;
        }
        int rem = n%8;
        return ans+rem*cnt;
    }
};