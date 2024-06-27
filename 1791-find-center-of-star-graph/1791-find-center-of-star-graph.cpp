class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(auto it : edges){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        int n = mp.size();
        for(auto it : mp){
            if(it.second == n-1) return it.first;
        }
        return -1;
    }
};