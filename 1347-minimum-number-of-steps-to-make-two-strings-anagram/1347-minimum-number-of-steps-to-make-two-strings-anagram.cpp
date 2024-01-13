class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mp(26,0);
        for(auto it:s){
            mp[it-'a']++;
        }
        int ans=0;
        for(auto it : t){
            mp[it-'a']--;
        }
        for(auto it: mp){
            if(it<0) ans+=abs(it);
        }
        return ans;
    }
};