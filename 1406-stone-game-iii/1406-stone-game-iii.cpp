class Solution {
public:
int dp[50001];
    int solve(vector<int>& nums, int i){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i] != INT_MIN) return dp[i];
        dp[i] = INT_MIN;
        int sum = 0;
        for(int x =0;i+x<nums.size() && x<3;x++){
            sum += nums[i+x];
            dp[i] = max(dp[i],sum-solve(nums,i+x+1));
        }
        return dp[i];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        // memset(dp,INT_MIN,sizeof(dp));
        int n = stoneValue.size();
        fill(dp,dp+50001,INT_MIN);
        dp[n]=0;
        int ans = solve(stoneValue,0);
        if(ans>=0){
            return ans==0?"Tie":"Alice";
        }
        else{
            return "Bob";
        }
    }
};