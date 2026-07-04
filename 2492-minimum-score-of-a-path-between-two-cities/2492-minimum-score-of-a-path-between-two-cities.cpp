class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads){
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it : roads){
            adj[it[0]-1].push_back({it[2],it[1]-1});
            adj[it[1]-1].push_back({it[2],it[0]-1});
        }
        queue<int> q;
        q.push(0);
        vector<bool> vis(n);
        vis[0]=true;
        int ans = INT_MAX;
        while(!q.empty()){
            auto node = q.front();q.pop();
            vis[node] = true;
            for(auto& [c,nbr] : adj[node]){
                ans = min(c,ans);
                if(!vis[nbr]){
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
};