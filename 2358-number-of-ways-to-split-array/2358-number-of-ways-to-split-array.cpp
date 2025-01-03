class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> suf(n+1);
        for(int i=n-1;i>=0;i--){
            suf[i] = suf[i+1]+nums[i];
        }
        long long run =0,ans=0;
        for(int i=0;i<n-1;i++){
            run += nums[i];
            if(run >= suf[i+1]){
                ans++;
            }
        }
        return ans;
    }
};