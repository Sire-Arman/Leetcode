class Solution {
public:
    bool bfs(int node,vector<int>& vis, vector<vector<int>>& graph){
        queue<int>q;
        q.push(node);
        vis[node] = 0;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(int nbr : graph[n]){
                if(vis[nbr] == -1){
                    vis[nbr] = !vis[n];
                    q.push(nbr);
                }
                else if((vis[nbr] ==1 && vis[n] ==1) || (vis[nbr] == 0 && vis[n] == 0)){
                        return false;
                    }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i] == -1 && bfs(i,vis,graph) == false) return false;

        }
        return true; 
    }
};