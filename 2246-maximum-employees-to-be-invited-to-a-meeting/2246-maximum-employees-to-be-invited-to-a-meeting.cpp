class Solution {
public:
    int bfs(int node, vector<vector<int>>& adj, unordered_set<int>& vis) {
        int ans = 0;
        queue<pair<int,int>> q;
        q.push({node, 0});
        while(!q.empty()) {
            int it = q.front().first;
            int dis = q.front().second;
            q.pop();
            for(auto i : adj[it]) {
                if(vis.count(i)) continue;
                q.push({i, dis+1});
                vis.insert(i);
                ans = max(ans, dis+1);
            }
        }
        return ans;
    }
    
    int maximumInvitations(vector<int>& f) {
        int n = f.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            adj[f[i]].push_back(i);
        }
        
        vector<bool> vis(n, false);
        int maxCycle = 0, twoC = 0;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                unordered_map<int, int> visited;
                int curr = i;
                int dis = 0;
                
                while(true) {
                    if(vis[curr]) break;
                    vis[curr] = true;
                    visited[curr] = dis++;
                    int next = f[curr];
                    
                    if(visited.count(next)) {
                        int cycle = dis - visited[next];
                        maxCycle = max(maxCycle, cycle);
                        
                        if(cycle == 2) {
                            unordered_set<int> visitedNodes = {curr, next};
                            int extraLen = bfs(next, adj, visitedNodes) + 
                                           bfs(curr, adj, visitedNodes);
                            twoC += 2 + extraLen;
                        }
                        break;
                    }
                    curr = next;
                }
            }
        }
        
        return max(maxCycle, twoC);
    }
};