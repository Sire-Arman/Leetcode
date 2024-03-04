class Solution {
public:
    int solve(vector<int> &v, int i, int j,  vector<vector<vector<int>>> &dp){
        if(i+1 == j) return 0;
        int ans = INT_MAX;
        
        for(int k = i+1; k<j;k++){
            if(dp[i][j][k] != -1) ans = min(ans, dp[i][j][k]);
            else {dp[i][j][k] = min(ans, v[i]*v[j]*v[k] + solve(v,i,k,dp) + solve(v,k,j,dp)); ans = dp[i][j][k];}
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<vector<int>>> dp(50,vector<vector<int>>(50,vector<int> (50 ,-1)));
        return solve(values, 0, values.size()-1, dp);
    }
};