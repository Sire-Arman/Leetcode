class Solution {
public:
    bool cycle(vector<int> adj[], vector<int>& vis, int node, int prev){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) {if(cycle(adj,vis,it,node)) return true; }
            else if(prev != it) return true;
        }
        vis[node] =0;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n = e.size();
        vector<int> adj[n+1];
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
            if(cycle(adj,vis,e[i][0],-1)) return e[i];
        }
        return {};
    }
};