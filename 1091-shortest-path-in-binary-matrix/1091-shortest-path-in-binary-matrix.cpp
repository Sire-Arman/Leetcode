class Solution {
public:
    vector<int> dx = {-1,0,1,0,1,1,-1,-1};
    vector<int> dy = {0,1,0,-1,1,-1,1,-1};
    int solve_bfs(vector<vector<int>>& grid){
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        vector<vector<bool>> vis(n,vector<bool>(n));
        queue<tuple<int,int,int>> dq;
        dq.push({1,0,0});
        vis[0][0] = true;
        while(!dq.empty()){
            auto [w,x,y] = dq.front();dq.pop();
            if(x==n-1 && y==n-1) return w;
            for(int i =0;i<8;i++){
                int nx = x+dx[i],ny = y + dy[i];
                if(nx>=0 && nx<n && ny >=0 && ny < n && !grid[nx][ny] && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    dq.push({w+1,nx,ny});
                    }
                }
            }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return solve_bfs(grid);
    }
};