class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> node(n,0);
        for(auto it : roads){
            node[it[0]]++;
            node[it[1]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({node[i],i});
        }
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            node[x.second] = n--;
        }        
        long long ans =0;
        for(auto it : roads){
            ans += node[it[0]];
            ans += node[it[1]];
        }
        return ans;
    }
};