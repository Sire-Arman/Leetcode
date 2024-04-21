class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int row = grid.size();
        int col = grid[0].size();
        vis[r][c] = 1;
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            int rw = q.front().first;
            int cl = q.front().second;
            q.pop();
            int nr = rw+1, nc = cl;
                    if(nr >=0 && nc>=0 && nr <row && nc <col && grid[nr][nc] == '1' && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
            nr = rw-1;
            if(nr >=0 && nc>=0 && nr <row && nc <col && grid[nr][nc] == '1' && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
            nc = cl+1, nr = rw;
            if(nr >=0 && nc>=0 && nr <row && nc <col && grid[nr][nc] == '1' && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
            nc = cl-1;
            if(nr >=0 && nc>=0 && nr <row && nc <col && grid[nr][nc] == '1' && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
    }
    void dfs(vector<vector<char>>& grid,int row, int col){
        if(row<0 ||col<0|| row>= grid.size() || col>= grid[0].size() || grid[row][col] == '0') return;
            grid[row][col] = '0';
            dfs(grid,row+1,col);
            dfs(grid,row,col+1);
            dfs(grid,row-1,col);
            dfs(grid,row,col-1);  
        }
    int numIslands(vector<vector<char>>& grid) {
        // function<void(int ,int)> dfs = [&](int row, int col){
        //     if(row<0 ||col<0|| row>= grid.size() || col>= grid[0].size() || grid[row][col] == '0') return;
        //     grid[row][col] = '0';
        //     dfs(row+1,col);
        //     dfs(row,col+1);
        //     dfs(row-1,col);
        //     dfs(row,col-1);  
        // };
            int n = grid.size();
            int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt =0;
        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};