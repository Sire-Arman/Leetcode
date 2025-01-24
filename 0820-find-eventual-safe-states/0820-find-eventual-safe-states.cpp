class Solution {
public:
    void bfs(vector<int> adj[], vector<int>& indeg, queue<int>& q, vector<int>& ans){
        while(!q.empty()){
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for(auto it : adj[x]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& vis,vector<int>& path, int node,vector<int>& safe){
        vis[node] = 1;
        path[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(graph,vis,path,it,safe)) return true;
            }
            else if(path[it]) {
                 return true;
            }
        }
        safe[node] = 1;
        path[node] =0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> indeg(n,0);
        vector<int> adj[n];
        queue<int> q;
        // vector<int> vis(n,0);
        // vector<int> path(n,0);
        // vector<int> safe(n,0);
        // for(int i=0;i<n;i++){
        //  dfs(graph,vis,path,i,safe);
        // }
        // for(int i=0;i<n;i++){
        //  if(safe[i]) ans.push_back(i);
        // }
        // return ans;
        for(int i=0;i<n;i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indeg[i] == 0) q.push(i);
        }
        bfs(adj,indeg,q,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};