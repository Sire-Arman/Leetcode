class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0,n=chalk.size();
        vector<long long> prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1]+chalk[i-1];
        }
        long long maxi = prefix[n];
        maxi = k%maxi;
        for(int i=0;i<=n;i++){
            if(prefix[i]>maxi){
                return i-1;
            }
        }
        return 0;
    }
};