class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int cur){
        if(sr<0 || sc <0 || sr>=image.size() || sc >= image[0].size() || image[sr][sc] == color || image[sr][sc] != cur) return;
        image[sr][sc] = color;
        dfs(image, sr+1,sc,color,cur);
        dfs(image, sr-1,sc,color,cur);
        dfs(image, sr,sc-1,color,cur);
        dfs(image, sr,sc+1,color,cur);
        
    }
    void bfs(vector<vector<int>>& image, int sr, int sc, int color, int cur){
        int n = image.size();
        int m = image[0].size();
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        // image[sr][sc] = color;
        vector<vector<int>> vis(n, vector<int> (m,0));
        vis[sr][sc] =1;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            image[r][c] = color;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >=0 && nr < n && nc >=0 && nc < m && image[nr][nc] == cur && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
            
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // dfs(image,sr,sc,color,image[sr][sc]);
        bfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};