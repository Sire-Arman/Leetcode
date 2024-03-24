class Solution {
public:
//     int solve(vector<int> &arr,map<int,int> &mp, int i){
        
//         int ans = INT_MIN;
//         for(int j=i;j<arr.size();j++){
//         ans = max(ans, arr[j]-mp[j]);
//         }
//         return ans;
//     }
    int maxProfit(vector<int>& arr) {
        int maxi = INT_MIN;
        int mini = arr[0];
        int n = arr.size();
        for(int i = 1;i<n;i++){
            maxi  = max(maxi, arr[i]-mini);
            mini = min(arr[i],mini);
        }
        return maxi>0?maxi:0;
    }
};