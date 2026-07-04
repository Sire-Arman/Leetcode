class Solution {
public:
    int MOD = 1e9+7;
    vector<int> shortestPathDistance(vector<vector<pair<int,int>>>& adj){
        int n = adj.size();
        vector<int> dis(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;
        vector<bool> vis(n,false);
        dis[n-1] = 0;
        pq.push({0,n-1});
        vis[n-1] = true;
        while(!pq.empty()){
            auto [cost,node] = pq.top();pq.pop();
            vis[node] = true;
            if(cost>dis[node]) continue;
            for(auto& [w,t]: adj[node]){
                if(!vis[t] && dis[t]> dis[node]+w){
                    dis[t] = dis[node]+w;
                    pq.push({dis[t],t});
                }
            }
        }
        return dis;
    }
    int solve_bfs(vector<vector<pair<int,int>>>& adj,vector<int>& shortestPath){
        int n = adj.size();
        int ans = 0;
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            int node = q.front();q.pop();
            if(node == n-1) ans +=1;
            for(auto& [w,t]: adj[node]){
                if(shortestPath[t] < shortestPath[node]){
                    q.push(t);
                }
            }
        }
        return ans;
    }
    long long solve_dp(vector<vector<pair<int,int>>>& adj, vector<int>& dist,vector<int>& dp, int n, int node){
        if(node == n-1) return 1;
        if(dp[node] != -1) return dp[node];
        long long count = 0;
        for(auto& [w,t]:adj[node]){
            if(dist[t]< dist[node]){
                count = (count + solve_dp(adj,dist,dp,n,t))%MOD;
            }
        }
        return dp[node] = count;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dp(n,-1);
        for(auto &it: edges){
            adj[it[0]-1].push_back({it[2],it[1]-1});
            adj[it[1]-1].push_back({it[2],it[0]-1});
        }
        vector<int> shortestPath = shortestPathDistance(adj);
        return solve_dp(adj,shortestPath,dp,n,0);
    }
};