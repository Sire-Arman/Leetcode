class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,int> mp;
        int ans =-1;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]){
                ans = max(ans,i-mp[s[i]]);
            }
            else mp[s[i]] = i+1;
        }
        return ans;
    }
};