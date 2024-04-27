class Solution {
public:
    int mod = 1e9+7;
    int solve(int z, int o, int l){
        vector<vector<vector<long long>>> dp(o+1,vector<vector<long long>>(z+1,vector<long long> (2,0)));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        for(int i=0;i<=o;i++){
            for(int j=0;j<=z;j++){
                for(int k=1;k<=l;k++){
                    if(i-k >=0 ) dp[i][j][1] = (dp[i][j][1]+dp[i-k][j][0])%mod;
                    if(j-k >= 0) dp[i][j][0] = (dp[i][j][0] + dp[i][j-k][1])%mod;
                }
            }
        }
        long long a = dp[o][z][0];
        long long b = dp[o][z][1];
        return static_cast<int>((a+b)%mod);
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        return solve(zero,one,limit);
    }
};