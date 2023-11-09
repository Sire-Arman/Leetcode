class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        if(n==0 || n==1){
            return n;
        }
        vector<long> mp;
        long long sum=0;
        int curcnt =0;
        char ch = s[0];
        for(int i=0;i<n;i++){
            if(ch == s[i]){
                curcnt++;
            }
            else{
                mp.push_back(curcnt);
                curcnt = 1;
                ch = s[i];
            }
        }
        mp.push_back(curcnt);
        for(long it: mp){
            long long tmp = it * (it + 1); 
            long long val = tmp/2;
            sum = (sum + val)%1000000007;
        }
        return sum;
    }
};