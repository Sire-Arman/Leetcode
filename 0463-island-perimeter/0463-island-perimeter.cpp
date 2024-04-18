class Solution {
public:
    int check(vector<vector<int>>& grid, int i,int j){
        int cnt =0;
        if(i==0 ||(i>0 && grid[i-1][j] == 0)) cnt++;
        if(i==grid.size()-1 || (i<grid.size()-1 && grid[i+1][j] == 0)) cnt++;
        if(j==0 || (j>0 && grid[i][j-1] == 0)) cnt++;
        if(j == grid[0].size()-1 || (j<grid[0].size()-1 && grid[i][j+1] == 0)) cnt++;
        return cnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri=0;
        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    peri += check(grid,i,j);
                }
            }
        }
        return peri;
    }
};