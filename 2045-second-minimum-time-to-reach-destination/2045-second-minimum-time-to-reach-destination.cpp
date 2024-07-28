class Solution {
public:
    int bfs(vector<vector<int>>& adj, int time, int change){
        // queue<pair<int,int>> q;
        int n = adj.size()-1;
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});  // (time, node)

        vector<int> uniqueVisit(n + 1, 0);  // To track the number of unique visits
        vector<int> dis(n + 1, -1);  // To store the minimum time to reach each node
        
        while (!q.empty()) {
            auto [t, node] = q.top();
            q.pop();  // Get the node with the smallest time
            
            if (dis[node] == t || uniqueVisit[node] >= 2) {
                continue;  // Skip if already visited or relaxed twice
            }
            
            uniqueVisit[node]++;
            dis[node] = t;
            
            if (node == n && uniqueVisit[node] == 2) {
                return dis[node];
            }
            
            // Calculate the leaving time (waiting for the green light)
            if ((t / change) % 2 != 0) {
                t = (t / change + 1) * change;
            }
            
            for (int nei : adj[node]) {
                q.push({t + time, nei});
            }
        }
        
        return -1;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int t, int c) {
        vector<int> ans;
        vector<vector<int>> adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // vector<int> vis(n,0);
        // bfs(adj,vis,ans,0,t,c);
        // sort(ans.begin(),ans.end());
        // for(int i=ans.size()-1;i>=0;i--){
        //     if(ans[i] != ans[ans.size()-1])
        //         return ans[i];
        // }
        return bfs(adj,t,c);
        
    }
};