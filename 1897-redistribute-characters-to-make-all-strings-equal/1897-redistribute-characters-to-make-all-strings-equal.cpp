class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int total =0;
        unordered_map<char,int> mp;
        for(auto it:words){
            total += it.size();
            for(auto i : it){
                mp[i]++;
            }
        }
        for(auto it:mp){
            if(it.second%n != 0)
                return false;
        }
        if(total %n != 0){
            return false;
        }
        return true;
    }
};