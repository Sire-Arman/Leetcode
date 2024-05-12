class Solution {
public:
    int checkmax(vector<vector<int>>& grid, int i ,int j){
        int maxi = grid[i][j];
        for(int a =0;a<3;a++){
            for(int b=0;b<3;b++){
                maxi = max(maxi, grid[i+a][j+b]);
            }
        }
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans (n-2,vector<int> (n-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                ans[i][j] = checkmax(grid,i,j);
            }
        }
        return ans;
    }
};