class Solution {
public:
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};
    // bool solve_bfs(vector<vector<int>>& grid, int i, int j, int h, vector<vector<bool>>& vis){

        // queue<tuple<int,int,int>> q;
        // q.push({0,0,h});
        // vis[i][j] = true;
        // bool ans = false;
        // if(grid[i][j]) h--;
        // for(int k =0;k<4;k++){
        //     int nx = i+dx[k];
        //     int ny = j+dy[k];
        //     if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && !vis[nx][ny]){ 
        //         ans = ans || solve_dfs(grid,nx,ny,h,vis);
        //         vis[nx][ny]=true;
        //     }

        // }
        // return ans;

    // }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        dis[0][0] = grid[0][0];
        while(!dq.empty()){
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();
            for(int i=0;i<4;i++){
                int nx = x+dx[i],ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int c = dis[x][y]+grid[nx][ny];
                    if(c<dis[nx][ny]){
                        dis[nx][ny] = c;
                        grid[nx][ny]>0?dq.push_back({nx,ny}):dq.push_front({nx,ny});
                    }
                }
            }
        }
        return dis[n-1][m-1]<health;
    }
};