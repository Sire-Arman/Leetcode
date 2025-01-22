class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    bool isSafe(vector<vector<int>> w, int r ,int c){
        if(r<0 || c<0 || r==w.size() || c == w[0].size() || w[r][c] > 0 || w[r][c] == INT_MIN){
            return false;
        }
        return 1;
    }
    void dfs(vector<vector<int>> &w, queue<pair<int,int>> &q){
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(w[i][j] == INT_MIN) continue;
                int height = w[i][j];
                for(int t =0;t<4;t++){
                    int a = i+dx[t];
                    int b = j+dy[t];
                    if(isSafe(w,a,b)){
                        w[a][b] = height+1;
                        q.push({a,b});
                    }
                    
                }
            }
                
        }
    }
    
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        int r = w.size();
        int c = w[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(w[i][j] == 1){
                    q.push({i,j});
                    w[i][j] = INT_MIN;
                }
            }
        }
        dfs(w,q);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(w[i][j] == INT_MIN){
                    w[i][j] = 0;
                }
            }
        }
        return w;
    }
};