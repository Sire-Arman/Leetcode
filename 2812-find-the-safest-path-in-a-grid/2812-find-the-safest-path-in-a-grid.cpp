class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        priority_queue<tuple<int,int,int>> pq;
        queue<pair<int,int>> q;
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        while(!q.empty()){
            auto [x,y] = q.front();q.pop();
            int val = dis[x][y];
            for(int t =0;t<4;t++){
                int nx = x+dx[t];
                int ny = y+dy[t];
                if(nx>=0 && nx<n && ny>=0 && ny<n && dis[nx][ny] > 1+val){
                    q.push({nx,ny});
                    dis[nx][ny] = dis[x][y]+1;
                }
            }
        }

        pq.push({dis[0][0],0,0});

        while(!pq.empty()){
            auto[a,b,c] = pq.top();
            pq.pop();
            if(b==n-1 && c==n-1) return a;
            vis[b][c] = true;
            for(int i =0;i<4;i++){
                int nx = b+dx[i];
                int ny = c+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny]){
                    int s = min(a,dis[nx][ny]);
                    vis[nx][ny] = true;
                    pq.push({s,nx,ny});
                }
            }
        }

        return -1;
    }
};