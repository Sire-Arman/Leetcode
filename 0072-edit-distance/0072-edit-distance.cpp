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
    int solveTab(string& w1, string& w2){
        int a =  w1.length(), b=  w2.length();
        if(a == 0) return b;
        if(b==0) return a;
        vector<int> curr (b+1,0);
        vector<int> prev (b+1,0);
            
        for(int i =0 ; i < b;i++){
           prev[i] = b-i;
        }
        // for(int i =0 ; i < a;i++){
        //     dp[i][b] = a-i;
        // }
        for(int i=a-1;i>=0;i--){
            for(int j=b-1;j>=0;j--){
                curr[b] = a-i;
                // prev[b] = a-i-1;
                int ans = 0;
                if(w1[i] == w2[j]){
                    ans = prev[j+1];
                }
                else{
                    int ins = curr[j+1];
                    int del = prev[j];
                    int rep = prev[j+1];
                    ans = 1+min(ins, min(del,rep));
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        
       return prev[0];
        
    }
    int minDistance(string word1, string word2) {
        // memset(dp,0, sizeof(dp));
        return solveTab(word1,word2);
    }
};