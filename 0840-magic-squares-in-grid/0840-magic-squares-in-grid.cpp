class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(r<3 || c<3) return 0;
        int cnt =0;
        for(int i=0;i<r-2;i++){
            for(int j=0;j<c-2;j++){
                bool c = true;
                vector<int> a(10,0);
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(grid[k][l] >=10 || grid[k][l] ==0 || a[grid[k][l]] == 1) {c=false; break;}
                        a[grid[k][l]]=1;
                    }
                    if(!c) break;
                }
                if(c){
                int r1 = grid[i][j]+grid[i+1][j]+grid[i+2][j];
                int r2 = grid[i][j+1] + grid[i+1][j+1]+grid[i+2][j+1];
                int r3 = grid[i][j+2] + grid[i+1][j+2]+grid[i+2][j+2];
                int c1 = grid[i][j] + grid[i][j+1]+grid[i][j+2];
                int c2 = grid[i+1][j] + grid[i+1][j+1]+grid[i+1][j+2];
                int c3 = grid[i+2][j] + grid[i+2][j+1]+grid[i+2][j+2];
                int d1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int d2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
                if(r1 == r2 && r2 == r3 && r3 == c1 && c1==c2 && c2==c3&&c3==d1 && d1==d2){
                    cnt++;
                }   
                }
            }
        }
        return cnt;
    }
};