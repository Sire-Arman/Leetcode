class Solution {
public:
    void dfs(vector<vector<int>>& brd,vector<vector<int>>& vis,int r, int c){
        int n = brd.size();
        int m = brd[0].size();
        if(r <0 || c<0 || r>=n || c>=m || vis[r][c] || brd[r][c] == 0) return ;
        vis[r][c] =1;
        dfs(brd,vis,r+1,c);
        dfs(brd,vis,r-1,c);
        dfs(brd,vis,r,c+1);
        dfs(brd,vis,r,c-1);
    }
    int numEnclaves(vector<vector<int>>& brd) {
          int n = brd.size();
          int m = brd[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            if(!vis[i][0] && brd[i][0] == 1){
                dfs(brd,vis,i,0); 
            }
            if(!vis[i][m-1] && brd[i][m-1] == 1){
                dfs(brd,vis,i,m-1); 
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && brd[0][j] == 1){
                dfs(brd,vis,0,j);
            }
            if(!vis[n-1][j] && brd[n-1][j] == 1){
                dfs(brd,vis,n-1,j); 
            }
        }
        int cnt =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j] && brd[i][j] == 1){
                   cnt++;
                }
            }
        }
        return cnt;
    }
};