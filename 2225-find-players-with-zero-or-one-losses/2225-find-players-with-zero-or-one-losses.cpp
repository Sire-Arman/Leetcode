class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> st;
        unordered_map<int,int> mp;
        for(auto it: matches){
            st.insert(it[0]);
            st.insert(it[1]);
            mp[it[1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto it: st){
           if (mp.find(it) == mp.end()){
               ans[0].push_back(it);
           }
            else if(mp[it] == 1){
                ans[1].push_back(it);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
        
    }
};