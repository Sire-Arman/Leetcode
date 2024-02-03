class Solution {
public:
    int solve(string s, unordered_set<string> &st, vector<int> &dp, int i){
        if(i==s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int mn = s.size();
        string str="";
        int n = s.size();
        for(int j = i;j<n;j++){
            str += s[j];
            int v = str.size();
            if(st.count(str)) v=0;
            
            mn = min(mn,v+solve(s,st,dp,j+1));
        }
        dp[i] = mn;
        return dp[i];
    }
    int minExtraChar(string s, vector<string>& d) {
        unordered_set<string> st(d.begin(),d.end());
        vector<int> dp(51,-1);
        return solve(s,st,dp,0);
    }
};