class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(),m=mat[0].size();
        vector<int> r(mat.size());
        vector<int> c(mat[0].size());
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            int a = mp[arr[i]].first;
            int b = mp[arr[i]].second;
            r[a]++;
            c[b]++;
            if(r[a]==m || c[b]==n) return i;
        }
        return -1;
    }
};