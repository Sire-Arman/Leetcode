class Solution {
public:
    int dp[101][101][2];
    // vector<vector<vector<int>>> dp;
    int solve(vector<int>& p, int i, int M, bool turn, vector<int>& prefix){
        if(i>=p.size()) return 0;
        if(dp[i][M][turn] != 0) return dp[i][M][turn];
        int ans=turn?0:INT_MAX;
        int lim = p.size()-i;
        for(int j=1;j<=min(lim,2*M);j++){
            int temp=0;
            if(turn){
                int t = max(M,j);
                temp = prefix[j+i]-prefix[i] + solve(p,j+i,t,!turn,prefix);
                ans = max(ans,temp);
            }
            else{
                int t = max(M,j);
                temp = solve(p,j+i,t,!turn,prefix);
                ans = min(ans,temp);
            }
        }
        return dp[i][M][turn] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp,INT_MIN,sizeof(dp));
        // dp.assign(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        vector<int> prefix(n+1,0);
        for(int i = 1;i<=n;i++){
            prefix[i] = prefix[i-1]+piles[i-1];
        }
        int M = 1;
        int ans =0;
        return solve(piles,0,M,true,prefix);
    }
};