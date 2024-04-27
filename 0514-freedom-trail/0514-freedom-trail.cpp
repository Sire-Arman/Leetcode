class Solution {
public:
    int helper(string& ring, string& key, int i, int pos, unordered_map<char,vector<int>>& mp, vector<vector<int>>& dp){
        if(i == key.size()) return 0;
        if(dp[i][pos] != -1) return dp[i][pos];
        int ans = INT_MAX;
         for(auto it : mp[key[i]]){
             int step = min(abs(pos-it), static_cast<int>(ring.size() - abs(pos-it)));
             // cout<<step<<endl;
             ans = min(ans, step + helper(ring,key, i+1,it,mp,dp));
         }
        return dp[i][pos] = ans;
    }
    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<ring.size();i++){
            mp[ring[i]].push_back(i);
        }
        vector<vector<int>> dp(101, vector<int>(101,-1));
        return helper(ring, key, 0,0,mp, dp) + key.size();
    }
};