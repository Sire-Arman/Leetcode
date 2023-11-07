class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        map<int,int> maxrow;
        map<int,int> maxcol;
        int n = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxcol[j] = max(grid[i][j],maxcol[j]);
                maxrow[i] = max(grid[i][j],maxrow[i]);
            }
        }
        // for(auto it : maxcol){
        //     cout<<it.second<<" ";
        // }
        // cout<<endl;
        // for(auto it : maxrow){
        //     cout<<it.second<<" ";
        // }
        int sum =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val = min(maxcol[j],maxrow[i]);
                sum += val-grid[i][j];
            }
        }
        return sum;
    }
};