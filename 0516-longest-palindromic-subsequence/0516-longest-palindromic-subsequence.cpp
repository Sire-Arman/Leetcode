class Solution {
public:
    int solve(string &s, string& temp, int i, int j){
        if(i == s.size() || j == s.size()) return 0;
        int ans = 0;
        if(s[i] == temp[j]){
            ans = max(ans, 1 + solve(s, temp, i+1,j+1));
        }
        else{
            ans = max(solve(s, temp , i,j+1), solve(s, temp,i+1,j));
        }
        return ans;
    }
    int solveTab(string &s, string& temp){
        // if(i == s.size() || j == s.size()) return 0;
        int n = s.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        for(int i = n-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                int ans =0;
                if(s[i] == temp[j]){
                    ans = max(ans, 1 + next[j+1]);
                }
                else{
                    ans = max(curr[j+1], next[j]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        
        return curr[0];
    }
    int longestPalindromeSubseq(string s) {
        string temp = s;
        reverse(s.begin(), s.end());
        return solveTab(temp,s);
    }
};