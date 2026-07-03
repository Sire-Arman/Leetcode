class Solution {
public:
    int solve_dijkstra(vector<vector<pair<int,int>>>& adj, int k){
        int n = adj.size();
        vector<int> dis(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k-1});
        dis[k-1] = 0;
        int ans = -1;
        while(!pq.empty()){
            auto [x,y] = pq.top();pq.pop();
            if(dis[y]<x) continue;
            for(auto it : adj[y]){
                int v = it.first,w = it.second;
                if(dis[v] > dis[y]+w){
                    dis[v] = dis[y]+w;
                    pq.push({dis[v],v});
                }
            }
        }
        ans = *max_element(dis.begin(),dis.end());
        return ans==INT_MAX?-1:ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it : times){
            adj[it[0]-1].push_back({it[1]-1,it[2]});
        }
        return solve_dijkstra(adj,k);
    }
};