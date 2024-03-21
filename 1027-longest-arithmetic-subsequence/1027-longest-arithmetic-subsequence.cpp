class Solution {
public:
    int solve(vector<int>& nums, int i, int diff,unordered_map<int,int> dp[]){
        if(i<0) return 0;
        if(dp[i].count(diff)) return dp[i][diff];
        int ans = 0;
        // int temp = nums[i];
        for(int j = i-1;j>=0;j--){
            if(nums[j] - nums[i] == diff){
                ans = max(ans, 1+solve(nums,j,diff,dp));
            }
        }
        return dp[i][diff] = ans;
        
    }
    // int longestArithSeqLength(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n<=2) return n;
    //     unordered_map<int,int> dp[n+1];
    //     int maxi = 0;
    //     for(int i=0;i<n;i++){
    //         for(int j = i+1;j<n;j++){
    //             int diff = nums[i]-nums[j];
    //             maxi = max(maxi,2 + solve(nums, i,diff,dp));
    //             // int k = i-1;
    //             // int temp = nums[i];
    //             // while(k>=0){
    //             //     if(nums[k]-temp == diff){
    //             //         cnt++;
    //             //         temp = nums[k];
    //             //     }
    //             //         k--;
    //             // }
    //         }
    //     }
    //     return maxi;
    // }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int ans =0;
        unordered_map<int,int> dp[n+1];
        for(int i = 1;i<n;i++){
            for(int j=0;j<i;j++){
                int cnt = 1;
                int diff = nums[i]- nums[j];
                if(dp[j].count(diff)) cnt = dp[j][diff];
                dp[i][diff] =1+cnt;
                ans = max(ans,dp[i][diff]);
            }
        }
        
        return ans;
    }
};