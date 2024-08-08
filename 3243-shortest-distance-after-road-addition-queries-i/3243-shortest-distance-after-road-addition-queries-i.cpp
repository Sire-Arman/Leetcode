class Solution {
public:
    int bfs(int s, int e , vector<vector<int>>& arr){
        int n= arr.size();
        vector<int> vis(n,-1);
        queue<int> q;
        vis[s] = 0;
        q.push(s);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == e){
                return vis[curr];
            }
            for(auto nbr : arr[curr]){
                if(vis[nbr] == -1){
                q.push(nbr);
                vis[nbr]= vis[curr]+1;
                }
            }
        }
        return -1;
        
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i].push_back(i+1);
        }
        vector<int> res(q.size());
        for(int i=0;i<q.size();i++){
            auto it = q[i];
            arr[it[0]].push_back(it[1]);
            res[i] = bfs(0, n-1, arr);
        }
        return res;
        
    }
};