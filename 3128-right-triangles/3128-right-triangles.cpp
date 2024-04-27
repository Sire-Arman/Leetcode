class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n<2 || m<2) return 0;
        vector<int> row(n,0);
        vector<int> col(m,0);
        long long ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i]+= grid[i][j];
                col[j] += grid[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]) ans += (row[i]-1) * (col[j]-1);
            }
        }
        return ans;
    }
};