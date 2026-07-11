class DSU{
    public:
    int size;
    vector<int> rank,parent;
        DSU(int n, vector<vector<int>>& adj){
            size = n;
            rank.resize(n,0);
            parent.resize(n);
            iota(parent.begin(),parent.end(),0);
        }
        
        int find(int i){
            int root = parent[i];
            if(root != parent[root]) parent[i] = find(root);
            return root;
        }

        void unite(int i, int j){
            int irep = find(i);
            int jrep = find(j);
            if(irep == jrep) return;
            if(rank[irep]<rank[jrep]){
                rank[jrep] = rank[irep];
            } else if(rank[irep]>rank[jrep]){
                rank[irep] = rank[jrep];
            }
            else{
                rank[irep]++;
            }
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
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return bfs(adj,n);
    }
};