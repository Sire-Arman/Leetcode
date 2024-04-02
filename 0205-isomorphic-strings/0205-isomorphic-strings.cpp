class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return 0;
        map<int,int> mp1;
        map<int,int> mp2;
        for(int i =0;i<s.size();i++){
            if(mp1[t[i]] && mp1[t[i]] != s[i]) return 0;
            else if(mp2[s[i]] && mp2[s[i]] != t[i]) return 0;
            mp1[t[i]] = s[i];
            mp2[s[i]] = t[i];
        }
        return 1;
    }
};