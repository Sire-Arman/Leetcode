class Solution {
public:
    long long maximumStrength(vector<int>& nums, long long k) {
        long long n = nums.size();
        long long ans = -1e13;
        vector<vector<long long int>> dp(n, vector<long long int>(k,-1e13));
        dp[0][0] = nums[0]*k;
        for(long long i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0]+nums[i]*k,nums[i]*k);
        }
        for(long long j=1;j<k;j++){
            long long s = ((k-j)&1)?1:-1;
            for(long long i =j;i<n;i++){
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + nums[i]*(k-j)*s;
            }
        }
        for(long long i=0;i<n;i++){
            ans = max({ans,dp[i][k-1]});
        }
        return ans;
    }
};