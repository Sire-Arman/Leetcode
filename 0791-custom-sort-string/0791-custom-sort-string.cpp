class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(auto &it : s) mp[it]++;
        string ans="";
        for(auto &it : order){
            int x = mp[it];
            ans.append(x,it);
            mp.erase(it);
        }
        for(auto &it : mp){
                ans.append(it.second,it.first);
        }
        return ans;
         
    }
};