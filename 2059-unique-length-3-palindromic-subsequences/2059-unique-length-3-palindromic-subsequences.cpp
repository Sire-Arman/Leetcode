class Solution {
public:
    bool isValid(string s){
        if(s.size()!= 3) return false;
        return s[0]==s[2]; 
    }
    void helper(string& s, int i, int c,string a, set<string>& st, vector<vector<string>>& dp){
        if(c==3 && isValid(a)){
            dp[i-1][c] = a;
            st.insert(a);
            return;
        }
        if(c>3 || i==s.size()) return;
        if(dp[i][c] != ""){
            st.insert(dp[i][c]);
            return;
        }

        helper(s,i+1,c+1,a+s[i],st,dp);
        helper(s,i+1,c,a,st,dp);
        
    }
    int countPalindromicSubsequence(string s) {
        // set<string> st;
        // vector<vector<string>> dp(s.size(),vector<string> (4,""));
        // helper(s,0,0,"",st,dp);
        // return st.size();
        vector<int> pref(26);
        vector<int> suff(26);
        set<string> st;
        int n = s.size();
        for(int i=n-1;i>=1;i--){
                int ind = s[i]-'a';
            suff[ind]++;
        }
        pref[s[0]-'a']++;

        for(int i=1;i<s.size()-1;i++){
            int ind = s[i]-'a';
            suff[ind]--;
            for(int j=0;j<26;j++){
                if(pref[j]>0 && suff[j]>0){
                    char a = 'a'+j;
                    string x = "";
                    x+=a;
                    x+=s[i];
                    x+=a;
                    st.insert(x);
                }
            }
            pref[ind]++;
        }
        return st.size();
    }
};