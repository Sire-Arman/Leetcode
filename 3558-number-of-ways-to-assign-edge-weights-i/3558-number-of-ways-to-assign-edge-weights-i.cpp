class Solution {
public:
    int MOD = 1e9+7;
    long long power(int a, int b){
        if(b==0) return 1;
        long long x = power(a,b/2);
        if(b&1) x = (x*x*a*1LL)%MOD;
        else x = (x*x)%MOD;
        return x;
    }
    void solve_dfs(vector<vector<int>>& adj, int i,int p, int l, long long& ans){
        bool isLeaf = true;
        for(int j=0;j<adj[i].size();j++){
            if(p==adj[i][j]) continue;
            isLeaf = false;
            solve_dfs(adj,adj[i][j],i,l+1,ans);
        }
        if(isLeaf){
            long long val  = power(2,l-1);
            ans = max(ans,val);
        } 
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+2);
        long long ans = 0;
        for(int i =0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        solve_dfs(adj,1,-1,0,ans);
        return ans;
        // return power(2,n-1);
    }
};