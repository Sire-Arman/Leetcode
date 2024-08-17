class Solution {
public:
    vector<long long> left,right;
    long long solve( int c, vector<vector<int>>& p, int i,vector<vector<long long>>& dp){
        if(i == p.size()-1){
            return dp[i][c] = p[i][c];
        }
        if(dp[i][c] != -1) return dp[i][c];
        long long maxi =0;
        if(c==0) right_left_max(i,p,dp);
        return dp[i][c] = p[i][c]+max(left[c],right[c]);
        
        
    }
    void right_left_max(int i, vector<vector<int>>& points,vector<vector<long long>>& dp){
        // Compute max from left to col j=0...c-1
        int c =points[0].size();
        left[0]=solve(0, points,i+1,dp);
        for (int j=1; j < c; j++)
            left[j]=max(left[j-1]-1, solve( j, points,i+1,dp));

        // Compute max from right downto col j=c-1...0
        right[c-1]=solve( c-1, points,i+1,dp);
        for (int j=c-2; j >= 0; j--)
            right[j] = max(right[j+1]-1, solve(j, points,i+1,dp));
    }

    long long maxPoints(vector<vector<int>>& p) {
        int r = p.size();
        int c = p[0].size();
        left.assign(c, LLONG_MIN);
        right=left;
        vector<vector<long long>> dp(r+1,vector<long long>(c+1,-1));
        long long ans =0;
        for(int j=0;j<c;j++){
            ans = max(ans, solve(j,p,0,dp));
        }
        return ans;
    }
};