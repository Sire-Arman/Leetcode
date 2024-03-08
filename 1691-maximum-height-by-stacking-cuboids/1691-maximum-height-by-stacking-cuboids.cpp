class Solution {
public:
    bool check(vector<int> b, vector<int> a){
        if (a[0] <= b[0] && a[1]<=b[1] && a[2]<=b[2]) return true;
        else return false;
    }
    int solveTab(vector<vector<int>> &cub){
        int n = cub.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        for(int i = n-1;i>=0;i--){
            for(int j = i-1;j>=-1;j--){
                int take =0;
                if(j == -1 || check(cub[i],cub[j])){
                    take = cub[i][2] + next[i+1];
                }
                int nott = 0+next[j+1];
                curr[j+1] = max(take,nott);
            }
            next = curr;
        }
        return next[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &it : cuboids){
            sort(it.begin(),it.end());
        }
        sort(cuboids.begin(),cuboids.end());
        return solveTab(cuboids);
    }
};