class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        vector<int> ans;
        vector<int> prefix(n+1);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1]^arr[i-1];
        }
        for(auto it : q){
            ans.push_back(prefix[it[1]+1]^prefix[it[0]]);
        }
        return ans;
    }
};