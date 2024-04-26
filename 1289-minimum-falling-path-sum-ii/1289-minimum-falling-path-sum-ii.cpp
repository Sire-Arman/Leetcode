class Solution {
public:
    // int dp[201][201];
    int solve(vector<vector<int>>& grid, int i, int c, vector<vector<int>>& dp){
        if(i>=grid.size()) return 0;
        if(dp[i][c] != -1) return dp[i][c];
        int  ans = INT_MAX;
        for(int j=0;j<grid[0].size();j++){
            if(i == 0 || j != c){
                ans = min(ans, grid[i][j] + solve(grid,i+1,j,dp));
            }
        }
        return dp[i][c] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
            vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
                return solve(grid,0,0,dp);
        // int ans = INT_MAX;
        // for(int i=0;i<grid[0].size();i++){
        //     ans = min(ans, grid[0][i] + solve(grid,i+1,i,dp));
        // }
        // return ans;
    }
};