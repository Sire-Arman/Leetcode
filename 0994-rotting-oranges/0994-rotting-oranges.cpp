class Solution {
public:
    // void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,vector<vector<int>>& time, int r ,int c, int t){
    //     if(r<0 || c<0 || r>= grid.size() || c>=grid[0].size() || grid[r][c] == 0 || vis[r][c]) return;
    //     // if(grid[r][c] == 2) time[r][c] = 0;
    //     time[r][c] = min(t,time[r][c]);
    //     vis[r][c] =1;
    //     dfs(grid,vis, time, r+1,c,t+1);
    //     dfs(grid,vis, time, r-1,c,t+1);
    //     dfs(grid,vis, time, r,c+1,t+1);
    //     dfs(grid,vis, time, r,c-1,t+1);
    // }
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    void bfs(vector<vector<int>>& grid, queue<vector<int>> &q, vector<vector<int>>& vis, int& t){
         int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            auto x = q.front();
            int a = x[0],b = x[1],c = x[2];
            q.pop();
            for(int i =0;i<4;i++){
                int nr = a + dr[i];
                int nc = b + dc[i];
                if(nr >=0 && nr < n && nc >=0 && nc <m && grid[nr][nc] == 1 && ! vis[nr][nc]){
                    vis[nr][nc] = 2;
                    q.push({nr,nc,c+1});
                }
                    t = max(t,c);
            }
            
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n,vector<int> (m,0));
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) {q.push({i,j,0}); vis[i][j] = 2;}
            }
        }
        int t=0;
        bfs(grid,q,vis,t);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]) return -1;
            }
        }
        return t;
        
    }
};