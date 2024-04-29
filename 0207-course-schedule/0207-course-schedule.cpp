class Solution {
public:
    bool kahnalgo(vector<int> adj[], vector<int>& indeg, queue<int>& q){
        int s =0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            s++;
            for(auto it : adj[x]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        return (s == indeg.size());
    }
    bool canFinish(int n, vector<vector<int>>& pr) {
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
        return kahnalgo(adj,indeg,q);
    }
};