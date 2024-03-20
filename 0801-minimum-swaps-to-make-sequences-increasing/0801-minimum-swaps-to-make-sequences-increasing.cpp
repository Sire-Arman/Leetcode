class Solution {
public:
    int solve(vector<int>& n1, vector<int>& n2, int i, bool swapped,int p1,int p2, vector<vector<int>> &dp){
        if(i == n1.size()) return 0;
        int ans = INT_MAX;
        if(dp[i][swapped] != -1) return dp[i][swapped];
        if(swapped) swap(p1,p2);
        if(n1[i] > p1 && n2[i] > p2) ans = solve(n1,n2,i+1,0,n1[i],n2[i],dp);
        if(n1[i] > p2 && n2[i]>p1)  ans =min(ans, 1+ solve(n1,n2,i+1,1,n1[i],n2[i],dp));
        return dp[i][swapped] = ans;
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        int ans =0;
        return solve(nums1,nums2,0,0,-1,-1,dp);
    }
};