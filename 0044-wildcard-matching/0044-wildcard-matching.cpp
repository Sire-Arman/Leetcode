class Solution {
public:
    bool solve(string& s, string &p, int i, int j,vector<vector<int>> &dp){
        if(i>= s.length() && j >= p.length()) return true;
        if(i<s.length() && j >= p.length()){
            return false;
        }
        if(i==s.length() ){
            for(int k = p.length()-1;k>=j;k--){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(s[i] == p[j] || p[j] == '?'){
            ans = ans|| solve(s,p,i+1,j+1,dp);
        }
        else{
            if(p[j] == '*'){
                ans = ans ||  solve(s,p,i,j+1,dp);
                    ans = ans ||solve(s,p,i+1,j,dp);
            }
            else{
                ans = false;
            }
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.length() ,m = p.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(s,p,0,0,dp);
    }
};