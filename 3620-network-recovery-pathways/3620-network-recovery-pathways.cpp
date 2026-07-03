class Solution {
public:
    void topo_sort(vector<vector<pair<int,int>>>& adj,vector<int>& list){
        queue<int> q;
        int n = adj.size();
        vector<int> indeg(n,0);
        for(int i =0;i<n;i++){
            for(int j =0;j<adj[i].size();j++){
                indeg[adj[i][j].first]++;
            }
        }
        for(int i =0;i<n;i++){
            if(indeg[i] ==0) q.push(i);
        }

        while(!q.empty()){
            int f = q.front();
            list.push_back(f);
            q.pop();
            for(int j =0;j<adj[f].size();j++){ 
                indeg[adj[f][j].first]--;
                if(indeg[adj[f][j].first]==0){
                    q.push(adj[f][j].first);
                }
            }
        }

    }
    bool check(vector<vector<pair<int,int>>>& adj, vector<bool>& online, vector<int>& list,int thres, long long k){
        int n = adj.size();
        vector<long long> dp (n, LLONG_MAX);
        dp[0] = 0;
        for(int i =0;i<list.size();i++){
            long long u = list[i];
            if(dp[u] == LLONG_MAX) continue;
            for(auto &[v,w]: adj[u]){
                if(w>=thres && online[v]){
                    dp[v] = min(dp[v],dp[u]+(long long)w);
                }
            }
        }
        return dp[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        vector<int> list;
        int n = online.size();
        vector<int> costs;
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            costs.push_back(it[2]);
        }
        sort(costs.begin(),costs.end());
        costs.erase(unique(costs.begin(),costs.end()),costs.end());
        topo_sort(adj,list);
        int lo =0, hi = costs.size()-1;
        int res = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            bool ans = check(adj,online,list,costs[mid],k);
            if(ans){
                res = costs[mid];
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return res;

    }
};