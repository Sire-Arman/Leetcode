class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    int solve(vector<vector<int>>& adj){
        int n = adj.size(),m=adj[0].size();
        vector<vector<int>> h(n,vector<int>(m,INT_MAX));
         priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        h[0][0] = 0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [e,x,y] = pq.top();pq.pop();
            if(x==n-1 && y == m-1) return h[n-1][m-1];
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y+dy[i];
                if(nx>=0 && ny >=0 && ny<m && nx <n){
                    int eff = max(h[x][y],abs(adj[x][y]-adj[nx][ny]));
                    if(h[nx][ny] > eff){
                        h[nx][ny] = eff;
                        pq.push({h[nx][ny],nx,ny});
                    }
                }
            }
        }
        return h[n-1][m-1];

    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        return solve(heights);
    }
};