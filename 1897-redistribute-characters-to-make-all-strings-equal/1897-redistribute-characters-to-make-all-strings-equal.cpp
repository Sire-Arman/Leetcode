class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char,int> mp;
        for(auto it:words){
            for(auto i : it){
                mp[i]++;
            }
        }
        for(auto it:mp){
            if(it.second%n != 0)
                return false;
        }
        return true;
    }
};