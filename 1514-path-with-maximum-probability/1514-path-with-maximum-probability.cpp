class Solution {
public:
    double solve(vector<vector<pair<double,int>>>& adj,int s, int e){
        int n = adj.size();
        vector<bool> vis(n,false);
        vector<double> dis(n,0.00000);
        priority_queue<pair<double,int>> pq;
        vis[s] = true;
        dis[s] = 1.00000;
        pq.push({1.00000, s});
        while(!pq.empty()){
            auto [pr,node] = pq.top();pq.pop();
            if(node == e) return dis[node];
            vis[node] = true;
            if(pr<dis[node]) continue;
            for(auto& [x,y] : adj[node]){
                if(!vis[y] && dis[y]< dis[node]*x){
                    dis[y] = dis[node]*x*1.00000;
                    pq.push({dis[y],y});
                }
            }
        }
        return dis[e];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int s, int e) {
        vector<vector<pair<double,int>>> adj(n);
        for(int i =0;i<edges.size();i++){
            int a = edges[i][0],b=edges[i][1];
            adj[a].push_back({succProb[i],b});
            adj[b].push_back({succProb[i],a});
        }
        return solve(adj,s,e);
    }
};