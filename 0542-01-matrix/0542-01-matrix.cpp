class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& vis, vector<vector<int>>& dis, queue<vector<int>>& q){
         int n = mat.size();
         int m = mat[0].size();
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int a = x[0],b=x[1],c=x[2];
            dis[a][b] = c;
            for(int i=0;i<4;i++){
                int nr = a + dr[i];
                int nc = b + dc[i];
                if(nr>=0 && nr < n && nc >=0 && nc <m && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    if(mat[nr][nc] == 1){
                        q.push({nr,nc,c+1});
                    }
                    else{
                        q.push({nr,nc,0});
                    }
                }
            }
            
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m,0));
        vector<vector<int>> dis(n, vector<int> (m,0));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({i,j,0});
                }
            }
        }
        bfs(mat,vis,dis,q);
        return dis;
    }
};