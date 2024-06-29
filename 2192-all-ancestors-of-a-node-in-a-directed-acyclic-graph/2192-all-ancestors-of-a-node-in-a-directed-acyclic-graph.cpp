class Solution {
public:
    void dfs(int node,int parent,vector<vector<int>>& nodes,vector<vector<int>>& adj, vector<int>& vis){
        vis[node] =1;
        for(auto& it : adj[node]){
            if(!vis[it]){
                nodes[it].push_back(parent);
                dfs(it,parent,nodes,adj,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        // vector<set<int>> nodes(n);
        vector<vector<int>> ans(n);
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            dfs(i,i,ans,adj,vis);
        }
        for(int i=0;i<n;i++){
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
        
    }
};