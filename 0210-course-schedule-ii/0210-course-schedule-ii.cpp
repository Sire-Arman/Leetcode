class Solution {
public:
    bool kahnalgo(vector<int> adj[], vector<int>& indeg, queue<int>& q,vector<int>& ans){
        int s =0;
        while(!q.empty()){
            int x = q.front();
            ans.push_back(x);
            q.pop();
            s++;
            for(auto it : adj[x]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        return (s == indeg.size());
    }
    bool dfs(vector<int> adj[], vector<int>& vis, vector<int>& path, int node){
        vis[node] =1;
        path[node] =1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if (dfs(adj,vis,path,it)) return true;
            }
            else{
                if(path[it]) return true;
            }
        }
        path[node] =0;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
         vector<int> adj[n];
        vector<int> indeg(n,0);
        queue<int> q;
        for(int i=0;i<pr.size();i++){
           adj[pr[i][1]].push_back(pr[i][0]);
        }
        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        for(int i=0;i<n;i++) if(indeg[i] == 0) q.push(i);
        vector<int> ans;
        if(kahnalgo(adj,indeg,q,ans)) return ans;
        else return {};
    }
};