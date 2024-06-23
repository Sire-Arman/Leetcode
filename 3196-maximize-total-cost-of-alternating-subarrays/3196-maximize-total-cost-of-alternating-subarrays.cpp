class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        long long dp[100001][2];
        memset(dp,0,sizeof(dp));
        dp[1][0] = nums[0]+nums[1];
        dp[1][1] = nums[0]-nums[1];
        
        for(int i=2;i<nums.size();i++){
            dp[i][0] = max(dp[i-1][0]+nums[i], dp[i-1][1] + nums[i]);
            dp[i][1] = dp[i-1][0]-nums[i];
        }
        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};