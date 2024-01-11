class Solution {
public:
    #pragma GCC optimize("O3")
    vector<vector<long long>>dp{4001,vector<long long>(1001)};
    int MOD = 1e9+7;
    long long count(int s, int e, int k){
        if(s == e && k ==0){
            return 1;
        }
        if(k==0){
            return 0;
        }
        if(dp[s+1000][k] != -1)return dp[s+1000][k];
        
        long long a = count(s+1,e,k-1);
        a+= count(s-1,e,k-1);
        return dp[s+1000][k] = a%MOD;
    }
    int numberOfWays(int s, int e, int k) {
        #pragma unroll
        for(int i=0;i<=3001;i++){
            for(int j=0;j<=k;j++)
                dp[i][j] = -1;
        }
        long long ans = count(s,e,k);
        return ans%MOD;
    }
};