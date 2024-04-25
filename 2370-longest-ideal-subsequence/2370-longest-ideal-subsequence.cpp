class Solution {
public:
    int solve(int i, string& s, int k, int prev,vector<vector<int>>& dp){
        if(i == s.size()) return 0;
        if(prev != -1 && dp[i][prev] != -1) return dp[i][prev];
        int ans = INT_MIN;
        
        int inc =0,exc =0;
        if(prev == -1 || abs(s[i]-s[prev])<=k){
            // if(prev != -1) cout<<s[i]<<s[prev]<<endl;
            inc = 1 + solve(i+1,s,k,i,dp);
            exc = solve(i+1,s,k,prev,dp);
            ans = max(inc, exc);
        }
        
        else{
            ans =  max(ans,solve(i+1,s,k,prev,dp));
        }
        if(prev == -1) return ans;
        return dp[i][prev] = ans;
    }
    int solveTab(string& s, int k){
        int n = s.size();
        vector<int> curr(n+2,0);
        vector<int> next(n+2,0);
        // vector<vector<int>> dp (n+2, vector<int> (n+2,0));
        
        for(int i= n;i>=1;i--){
            for(int j=i-1;j>=0;j--){
                int ans = INT_MIN;
        
                int inc =0,exc =0;
                if(j == 0 || abs(s[i-1]-s[j-1])<=k){
                    // if(prev != -1) cout<<s[i]<<s[prev]<<endl;
                    inc = 1 + next[i];
                    exc = next[j];
                    ans = max(inc, exc);
                }

                else{
                    ans =  max(ans,next[j]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
        
    }
    int longestIdealString(string s, int k) {
        int dp[27] = {0};
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            char cc = s[i];
            int idx = cc - 'a';
            int maxi = -__INT_MAX__;

            int left = max((idx - k), 0);
            int right = min((idx + k), 26);

            for (int j = left; j <= right; j++) {
                maxi = max(maxi, dp[j]);
            }

            dp[idx] = maxi + 1;
        }

        int max = -__INT_MAX__;
        for (int i = 0; i < 27; i++) {
            if (dp[i] > max)
                max = dp[i];
        }

        return max;
    }
};