class Solution {
public:
    // void solve(vector<int>& nums, int i, int &mini){
    //    for(int i=0;i<nums.size();i++){
    //        dp[i] = max(dp[i]+i, dp[i-1]);
    //    }
    // }
    int jump(vector<int>& nums) {
       int n = nums.size();
        if(n==1 ) return 0;
        int prev =0,maxi =0,jump =0;
        for(int i =0;i<n-1;i++){
            maxi = max(maxi, i + nums[i]);
            
            if(i == prev){
                jump++;
                prev = maxi;
            }
        }
        return jump;
    }
};