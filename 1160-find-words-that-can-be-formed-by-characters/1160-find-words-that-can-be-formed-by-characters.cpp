class Solution {
public:
    bool check(string s, vector<int> val){
        for(int i=0;i<s.size();i++){
            if(val[s[i]-'a']==0){
                return false;
            }
            val[s[i]-'a']--;
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        int len=0;
        vector<int> ans(26,0);
        for(int i=0;i<chars.size();i++){
            ans[chars[i]-'a']++;
        }
        for(auto it : words){
            if(check(it,ans)){
                len+=it.size();
            }
        }
        return len;
    }
};