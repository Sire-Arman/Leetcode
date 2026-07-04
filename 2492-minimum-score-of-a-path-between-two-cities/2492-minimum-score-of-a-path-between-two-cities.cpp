class Solution {
public:
    int solve_bfs(vector<vector<pair<int,int>>>& adj){
        int ans = INT_MAX;
        int n = adj.size();
        vector<bool> vis(n);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            int node = q.front();q.pop();
            vis[node] = true;
            for(auto& [c,nbr] : adj[node]){
                ans = min(ans,c);
                if(!vis[nbr]) q.push(nbr);
            }
        }
        return ans;

    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it : roads){
            adj[it[0]-1].push_back({it[2],it[1]-1});
            adj[it[1]-1].push_back({it[2],it[0]-1});
        }
        return solve_bfs(adj);
    }
};