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
     bool solveTab(string& s, string &p){
        
         int n = s.length() ,m = p.length();
         vector<int> prev(m+1,0);
         vector<int> curr(m+1,0);
         // curr[m] = 1;
         prev[m] = 1;
         // vector<vector<int>> dp(n+1,vector<int> (m+1,0));
         // dp[n][m] = 1;
         for(int j=0;j<p.length();j++){
             bool flag = true;
              for(int k = p.length()-1;k>=j;k--){
                if(p[k] != '*') {flag = false;break;}
              }
            prev[j] = flag;
         }
         for(int i = n-1;i>=0;i--){
             for(int j=m-1;j>=0;j--){
                    bool ans = false;
                    if(s[i] == p[j] || p[j] == '?'){
                        ans = ans || prev[j+1];
                    }
                    else{
                        if(p[j] == '*'){
                            ans = ans || curr[j+1];
                                ans = ans || prev[j];
                        }
                        else{
                            ans = false;
                        }
                    }
                    curr[j] = ans;
             }
             prev = curr;
         }
       return prev[0];
    }
    bool isMatch(string s, string p) {
        int n = s.length() ,m = p.length();
        // vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solveTab(s,p);
    }
};