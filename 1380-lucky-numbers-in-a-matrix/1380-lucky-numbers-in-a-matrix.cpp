class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> r(m);
        vector<int> c(n);
        for(int i=0;i<m;i++){
            int mini = mat[i][0];
            for(int j=0;j<n;j++){
                mini = min(mini,mat[i][j]);
            }
            r[i] = mini;
        }
        for(int i=0;i<n;i++){
            int mini = mat[0][i];
            for(int j=0;j<m;j++){
                mini = max(mini,mat[j][i]);
            }
            c[i] = mini;
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(r[i] == c[j] && r[i] == mat[i][j]){
                   ans.push_back(mat[i][j]);
               }
            }
        }
        return ans;
    }
};