class Solution {
public:
    int solve(vector<int> &arr, int i, int j, map<pair<int,int>,int>& mp, vector<vector<int>>& dp){
        if(i == j) return 0;
        int ans = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i;k<j;k++){
            int a = mp[{i,k}];
            int b = mp[{k+1,j}];
            ans = min(ans,a*b + solve(arr,i,k,mp,dp) + solve(arr, k+1, j,mp,dp));
        }
        return dp[i][j] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>, int> mp;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            mp[{i,i}] = arr[i];
            for(int j = i+1;j<n;j++){
                mp[{i,j}]  = max(arr[j], mp[{i,j-1}]);
            }
        }
        int i =0,j = arr.size()-1;
        vector<vector<int>> dp(j+2, vector<int> (j+2,-1));
        return solve(arr,i,j,mp,dp);
    }
};