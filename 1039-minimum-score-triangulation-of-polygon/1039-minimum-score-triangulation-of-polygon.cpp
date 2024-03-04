class Solution {
public:
    int solve(vector<int> &v, int i, int j, vector<vector<int>> &dp){
        if(i+1 == j) return 0;
        int ans = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i+1; k<j;k++){
            ans = min(ans, v[i]*v[j]*v[k] + solve(v,i,k,dp) + solve(v,k,j,dp));
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(50,vector<int>(50,-1));
        return solve(values, 0, values.size()-1, dp);
    }
};