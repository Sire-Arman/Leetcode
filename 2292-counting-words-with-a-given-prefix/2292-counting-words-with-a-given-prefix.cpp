class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans =0;
        for(auto &it : words) {if(it.size()>=pref.size() && it.substr(0,pref.size())==pref) ans++;}
        return ans;
    }
};