class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        for(auto &it : s) mp[it]++;
        string ans="";
        for(auto &it : order){
            int x = mp[it];
            if(x){
                mp[it] =0;
                while(x--){
                    ans += it;
                }
            }
        }
        for(auto &it : mp){
            if(it.second){
                int x = it.second;
                it.second = 0;
                while(x--){
                    ans += it.first;
                }
            }
        }
        return ans;
         
    }
};