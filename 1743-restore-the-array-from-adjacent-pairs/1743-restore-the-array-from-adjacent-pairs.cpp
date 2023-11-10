class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
        int n= adj.size()+1;
        if(n==2){
            return adj[0];
        }
        vector<int> res;
        map<int,vector<int>> mp;
        for(auto it: adj){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int start = INT_MIN,left=INT_MIN;
        for(auto it:mp){
            if(it.second.size()==1){
                start = it.first;
                break;
            }
        }
        res.push_back(start);
        for(int i=1;i<n;i++){
             vector<int>& val = mp[start];
            int value = left == val[0]?val[1]:val[0];
            res.push_back(value);
            left = start;
            start=value; 
        }
        
        return res;
    }
};