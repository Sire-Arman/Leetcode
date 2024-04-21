class Solution {
public:
    bool solve(int dst, unordered_map<int,vector<int>> &mp, int cur,vector<int> & vis){
        if(cur == dst) return true;
        int ans = false;
        vis[cur] = 1;
        for(auto it : mp[cur]){
            if(!vis[it]) ans = ans || solve(dst,mp,it,vis);
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        unordered_map<int,vector<int>> mp;
        vector<int> vis(n,0);
        for(auto it : edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        return solve(dst,mp,src,vis);
    }
};