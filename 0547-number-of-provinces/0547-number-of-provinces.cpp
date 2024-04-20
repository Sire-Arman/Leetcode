class Solution {
public:
    int findCircleNum(vector<vector<int>>& isc) {
        vector<int> vis(isc.size(),0);
        function<void(int)> dfs = [&](int node){
            if(vis[node]==1) return;
            vis[node] = 1;
            for(int i=0;i<isc[node].size();i++){
                if(isc[node][i] == 1) dfs(i);
            }
        };
        int pr =0;
        for(int i=0;i<isc.size();i++){
            if(vis[i]!= 1){
                pr++;
                dfs(i);
            }
        }
        return pr;
    }
};