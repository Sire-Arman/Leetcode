class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    map<pair<int,int>,pair<int,int>> dp;
    int solve(vector<vector<pair<ll,int>>>& adj, int n){
        vector<ll> dis(n,LLONG_MAX);
        vector<ll> count(n,0LL);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<>> pq;
        pq.push({0,0});
        count[0] = 1;
        dis[0] = 0;
        while(!pq.empty()){
            auto [time,node] = pq.top();pq.pop();
            if(time > dis[node]) continue;
            for(auto& [t,p]: adj[node]){
                if(dis[p]> dis[node]+t){
                    dis[p] = dis[node]+t;
                    count[p] = count[node];
                    pq.push({dis[p],p});
                }
                else if(dis[p] == dis[node]+t){
                      count[p] = (count[p]+count[node])%MOD; 
                }
            }
        }
        return count[n-1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,int>>> adj(n);
        for(auto& it: roads){
            ll a = it[0],b=it[1],c=it[2];
            adj[a].push_back({c,b});
            adj[b].push_back({c,a});
        }
        return solve(adj,n);
    }
};