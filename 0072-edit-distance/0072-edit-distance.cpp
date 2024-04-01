class Solution {
public:
    int dp[501][501];
    int solve(string& w1, string& w2, int i, int j){
        if(i == w1.length()){
            return w2.length()-j;
        }
        if(j == w2.length()){
            return w1.length()-i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans =0;
        if(w1[i] == w2[j]){
            return solve(w1,w2,i+1,j+1); 
        }
        else{
            int ins = solve(w1,w2,i,j+1);
            int del = solve(w1,w2,i+1,j);
            int rep = solve(w1,w2, i+1,j+1);
            ans = 1+min(ins, min(del,rep));
        }
        return dp[i][j] = ans;
        
    }
    int minDistance(string word1, string word2) {
        
        memset(dp,-1, sizeof(dp));
        return solve(word1,word2,0,0);
    }
};