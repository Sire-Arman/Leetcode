class DSU{
    public:
    int size;
    vector<int> edgCnt,verCnt;
    vector<int> rnk,parent;
        DSU(int n){
            size = n;
            rnk.resize(n,0);
            parent.resize(n,0);
            iota(parent.begin(),parent.end(),0);
        }
        
        int find(int i){
            if(i != parent[i]) parent[i] = find(parent[i]);
            return parent[i];
        }

        void unite(int i, int j){
            int irep = find(i);
            int jrep = find(j);
            if(irep == jrep) return;
            if(rnk[irep]<rnk[jrep]){
                parent[irep] = jrep;
            } else if(rnk[irep]>rnk[jrep]){
                parent[jrep] = irep;
            }
            else{
                parent[jrep] = irep;
                rnk[irep]++;
            }
        }
        int countCompleteness(int n,vector<vector<int>>& adj){
            edgCnt.assign(n,0);
            verCnt.assign(n,1);
            int ans = 0;
            for(auto& it : adj){
                int r1 = find(it[0]),r2 = find(it[1]);
                if(r1 != r2){
                    unite(it[0],it[1]);
                    int root = find(it[0]);
                    edgCnt[root] = edgCnt[r1]+edgCnt[r2]+1;
                    verCnt[root] = verCnt[r1]+verCnt[r2];
                }
                else{
                    edgCnt[r1]++;
                }
            }
            for(int i =0;i<n;i++){
                if(find(i) == i){
                    int v = verCnt[i];
                    int e = edgCnt[i];
                    if(v*(v-1)/2 == e) ans++;
                }
            }
            return ans;
        }
};
class Solution {
public:
    int bfs(vector<vector<int>>& adj, int n){
        vector<bool> vis(n,false);
        queue<int> q;
        int ans = 0;
        for(int i =0;i<n;i++){
            if(vis[i]) continue;
            q.push(i);
            vis[i] =true;
            int cnt =0,vertex=0;
            while(!q.empty()){
                int node = q.front();q.pop();
                vertex++;
                vis[node] = true;
                for(auto &it : adj[node]){
                    cnt++;
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = true;
                    }
                }
            }
            if(vertex * (vertex - 1) == cnt) ans++;
        }
        return ans;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dsu.countCompleteness(n,edges);
        // return bfs(adj,n);
    }
};