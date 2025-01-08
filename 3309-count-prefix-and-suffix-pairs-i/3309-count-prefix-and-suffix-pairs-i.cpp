class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans =0;
        for(int i=0;i<words.size();i++){
            string p = words[i];
            for(int j = i+1;j<words.size();j++){
                string t = words[j];
                if(t.size()<p.size()) continue;
                if(t.substr(0,p.size()) == p && t.substr(t.size()-p.size(),p.size())== p) {ans++;}
            }
        }
        return ans;
    }
};