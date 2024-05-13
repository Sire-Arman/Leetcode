class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 0){
                    int c1 = 0;
                    bool prev1r= 0;
                    for(int k =j;k>=0;k--){
                        if(grid[i][k]) {prev1r = true; break;}
                    }
                    if(!prev1r){
                        for(int k =0;k<n;k++){
                           grid[i][k] = !grid[i][k];
                        }
                    }
                    else{
                        for(int k =0;k<m;k++){
                            if(grid[k][j] == 0) c1++;
                        }
                        if(c1 > (m-c1)){
                             for(int k =0;k<m;k++) grid[k][j] = !grid[k][j];
                        }
                    }
                }
            }
        }
        int ans =0;
        for(int i =0;i<m;i++){
            int x =0;
            for(int  j=0;j<n;j++){
                // cout<<grid[i][j]<<' ';
                if(grid[i][j]) x+= pow(2,n-1-j);
            }
            // cout<<endl;
            ans += x;
        }
        return ans;
    }
};