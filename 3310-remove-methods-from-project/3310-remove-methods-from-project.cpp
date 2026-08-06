class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& suspicious) {
        suspicious[node] = true;
        for (int nxt : adj[node]) {
            if (!suspicious[nxt]) {
                dfs(nxt, adj, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> suspicious(n, false);
        dfs(k, adj, suspicious);

        for (auto& e : invocations) {
            int u = e[0], v = e[1];
            if (suspicious[v] && !suspicious[u]) {
                vector<int> all(n);
                iota(all.begin(), all.end(), 0);
                return all;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) ans.push_back(i);
        }
        return ans;
    }
};