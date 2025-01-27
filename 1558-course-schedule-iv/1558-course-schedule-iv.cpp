class Solution {
public:
    bool bfs(int node, vector<unordered_set<int>>& tab, vector<int>& vis, int target){
        queue<int> q;
        q.push(node);
        vis[node] = true;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto &it : tab[t]){
                if(!vis[it]){
                    if(it == target) return true;
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<unordered_set<int>> tab(n);
        vector<bool> ans;
        for(auto & it : pre){
            tab[it[0]].insert(it[1]);
        }
        for(auto &it : q){
            vector<int> vis(n,0);
            ans.push_back(bfs(it[0],tab,vis,it[1]));
        }
        return ans;
    }
};