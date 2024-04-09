class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& grid, int i, int j, string  str,map<string, int> &mp){
        if(i == grid.size()-1 && j == grid[0].size()-1){
            if(mp[str] || grid[i][j] == 1) return 0;
            else {
                mp[str]++;
                return 1;
            }
        }
        else if(i>= grid.size() || j >= grid[0].size() || grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans = ans + solve(grid, i+1, j, str+'D',mp);
        ans = ans + solve(grid,i,j+1, str+'R',mp);
         return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        map<string, int> mp;
        return solve(grid,0,0,"",mp);
    }
};