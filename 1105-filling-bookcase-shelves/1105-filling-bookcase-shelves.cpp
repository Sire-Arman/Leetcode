class Solution {
public:
    int ans{INT_MAX};
    int W;
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        W = shelfWidth;
        vector<vector<int>> dp(books.size(), vector<int>(W+1, INT_MAX));
        return sol(books, 0,shelfWidth, 0, dp);
    }

    int sol(vector<vector<int>>& arr, int i, int w, int h, vector<vector<int>> &dp){
        if(i==arr.size()){
            return h; 
        }
        if(dp[i][w] != INT_MAX){
            return dp[i][w];
        }
        int width = arr[i][0];
        int height = arr[i][1];
        int maxH = max(h, height);
        if(w >= width){
            return dp[i][w] = min(sol(arr, i+1, w-width, maxH, dp), h+sol(arr, i+1, W-width, height, dp));
        } else {
            return dp[i][w] = h+sol(arr, i+1, W-width, height, dp);
        }
    }
};