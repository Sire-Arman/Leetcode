class Solution {
public:
    bool dfs(int node,vector<int>& vis, vector<vector<int>>& graph){
        // if(vis[node] != -1){
        //     if(node != par && vis[node] == vis[par]) return false;
        //     else return true;
        // } 
        // if(par == -1) vis[node] = 0;
        // else vis[node] = !vis[par];
        bool ans = true;
        for(auto it : graph[node]){
            if(vis[it] == -1) { 
                vis[it] = !vis[node]; 
                ans = ans && dfs(it,vis,graph);
            }
            else{
                if(it != node && vis[it] == vis[node]) return false;
            }
        }
        return ans;
    }
    bool bfs(int node, vector<int>& vis, vector<vector<int>>& graph){
        queue<int>q;
        q.push(node);
        vis[node] = 0;
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            for(auto nbr : graph[n]){
                if(vis[nbr] == -1){
                    if(vis[n] == 0) vis[nbr] = 1;
                    else vis[nbr] = 0;
                    q.push(nbr);
                }
                else{
                    if(vis[nbr] != -1 && vis[nbr] == vis[n]){
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            
            if(vis[i] == -1){
                vis[i] = 0;
                if(dfs(i,vis,graph) == false) return false;
            }
        }
        return true;
    }
};