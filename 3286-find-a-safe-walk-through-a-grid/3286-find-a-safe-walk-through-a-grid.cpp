class Solution {
public:
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};
    bool dijkstra(vector<vector<int>>& grid, int h){
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0] = grid[0][0];
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        while(!dq.empty()){
            auto [x,y] = dq.front();
            dq.pop_front();
            for(int i =0;i<4;i++){
                int nx = x+dx[i],ny = y+ dy[i];
                if(nx>=0 && nx <n && ny >=0 && ny < m && dis[x][y]+grid[nx][ny]<dis[nx][ny]){
                    if(grid[nx][ny]){
                        dq.push_back({nx,ny});
                    }
                    else{
                        dq.push_front({nx,ny});
                    }
                    dis[nx][ny] = dis[x][y]+grid[nx][ny];
                }
            }
        }
        return dis[n-1][m-1] < h;

    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // int n = grid.size(),m = grid[0].size();
        // vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        // deque<pair<int,int>> dq;
        // dq.push_front({0,0});
        // dis[0][0] = grid[0][0];
        // while(!dq.empty()){
        //     int x = dq.front().first;
        //     int y = dq.front().second;
        //     dq.pop_front();
        //     for(int i=0;i<4;i++){
        //         int nx = x+dx[i],ny = y+dy[i];
        //         if(nx>=0 && ny>=0 && nx<n && ny<m){
        //             int c = dis[x][y]+grid[nx][ny];
        //             if(c<dis[nx][ny]){
        //                 dis[nx][ny] = c;
        //                 grid[nx][ny]>0?dq.push_back({nx,ny}):dq.push_front({nx,ny});
        //             }
        //         }
        //     }
        // }
        // return dis[n-1][m-1]<health;
        return dijkstra(grid,health);
    }
};