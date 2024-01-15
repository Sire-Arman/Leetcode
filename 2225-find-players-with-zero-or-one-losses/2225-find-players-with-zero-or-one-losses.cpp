class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(auto it: matches){
            mp[it[1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto it: matches){
           if (mp[it[0]] == 0){
               ans[0].push_back(it[0]);
               mp[it[0]] = INT_MIN;
           }
            if(mp[it[1]] ==0){
                ans[0].push_back(it[1]);
                mp[it[1]] = INT_MIN;
            }
            if(mp[it[1]] ==1){
                ans[1].push_back(it[1]);
                mp[it[1]] = INT_MIN;
            }
            if(mp[it[0]] ==0){
                ans[1].push_back(it[0]);
                mp[it[0]] = INT_MIN;
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
        
    }
};