class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        int n = s.size();
        bool inStack[26] = {};
        vector<int> lastIdx(26,-1);
        for(int i =0;i<n;i++) lastIdx[s[i]-'a']=i;
        for(int i =0;i<n;i++){
            int idx = s[i]-'a';
            if(inStack[idx]) continue;
            while(!ans.empty() && ans.back()>s[i] && lastIdx[ans.back()-'a']>i){
                inStack[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans+=s[i];
            inStack[s[i]-'a'] = true;
        }
        return ans;
    }
};