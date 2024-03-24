class Solution {
public:
    int solve(vector<int> &arr,map<int,int> &mp, int i){
        
        int ans = INT_MIN;
        for(int j=i;j<arr.size();j++){
        ans = max(ans, arr[j]-mp[j]);
        }
        return ans;
    }
    int maxProfit(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        mp[0] = arr[0];
        for(int i = 1;i<n;i++){
                mp[i]  = min(arr[i], mp[i-1]);
        }
        return solve(arr,mp,0);
    }
};