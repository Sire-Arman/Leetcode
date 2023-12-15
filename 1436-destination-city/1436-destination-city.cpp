class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,string> mp;
        for(auto it: paths){
            mp[it[0]] = it[1];
        }
        string it = paths[0][0];
        while(mp[it] != ""){
            it = mp[it];
        }
        return it;
    }
};