class Solution {
public:
    long long solve(vector<vector<int>>& grid){
        int n = grid[0].size();
        long long pref = accumulate(grid[0].begin(),grid[0].end(),0LL),suff=0;
        long long maxi =LLONG_MAX,idx = -1;
        for(int i=0;i<n;i++){
           pref -= grid[0][i];
           maxi = min(maxi, max(pref,suff));
           suff+= grid[1][i];
        }
        return maxi;
    }
    
    long long gridGame(vector<vector<int>>& grid) {
     return solve(grid);   
    }
};