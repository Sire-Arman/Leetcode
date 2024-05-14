class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<int>>& vis, int i, int j){
        if(i<0 || j<0 || i==grid.size() || j == grid[0].size()) return 0;
        if(grid[i][j] == 0 || vis[i][j]) return 0;
        int ans =grid[i][j];
        // cout<<ans<<' ';
        vis[i][j] = 1;
        int a = solve(grid,vis,i+1,j);
        int b = solve(grid,vis,i-1,j);
        int c = solve(grid,vis,i,j+1);
        int d = solve(grid,vis,i,j-1);
        ans = (ans, grid[i][j] + max(a,max(b,max(c,d))));
        vis[i][j] = 0;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]){
                    vector<vector<int>> vis(n, vector<int>(m,0));
                    ans = max(ans,solve(grid,vis,i,j));
                    // cout<<endl;
                }
            }
        }
        return ans;
    }
};