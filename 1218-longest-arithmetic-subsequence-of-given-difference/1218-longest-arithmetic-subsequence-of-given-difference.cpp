class Solution {
public:
    // int solve(vector<int>& arr, int dif, int i){
    //     if(i== arr.size()) return 0;
    //     mp
    // }
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> dp;
        int ans = 0;
        
        for(int i =0;i<arr.size();i++){
            int dif = arr[i]-diff;
            
            int temp =0;
            if(dp.count(dif)){
                temp  = dp[dif];
            }
            dp[arr[i]] = 1 + temp;
            ans = max(ans,temp);
        }
        return ans+1;
    }
};