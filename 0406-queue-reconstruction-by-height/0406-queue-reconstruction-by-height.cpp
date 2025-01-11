class Solution {
public:
static bool cmp(vector<int>& a, vector<int>& b){
    return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]);
}
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        vector<vector<int>> ans;
       sort(p.begin(),p.end(),cmp);
        for(auto &it : p){
            ans.insert(ans.begin() + it[1],it);
        }
        return ans;
    }
};