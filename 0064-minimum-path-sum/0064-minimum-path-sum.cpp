class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& grid, int i , int j){
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return grid[i][j];
        }
        // if(i>= grid.size() ||j>= grid[0].size()) return INT_MAX;
        if(dp[i][j] != -1 ) return dp[i][j];
        int ans = INT_MAX;
         if(i+1< grid.size() ) ans = min(ans,grid[i][j] + solve(grid,i+1,j));
         if(j+1< grid[0].size()) ans = min(ans,grid[i][j] + solve(grid,i,j+1));
        return dp[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1, sizeof(dp));
        return solve(grid,0,0);
    }
};