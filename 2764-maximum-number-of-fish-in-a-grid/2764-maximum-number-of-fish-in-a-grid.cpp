class Solution {
public:
int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i, int j){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0 || vis[i][j]==1) return 0;
        int ans =grid[i][j];
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            ans += bfs(grid,vis,i+dx[k],j+dy[k]);
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m =  grid[0].size();
        int ans =0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0){
                    ans = max(ans, bfs(grid,vis,i,j));
                }
            }
        }
        return ans;
    }
};