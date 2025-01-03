class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long suf =0;
        for(int i=n-1;i>=0;i--){
            suf+=nums[i];
        }
        long long run =0,ans=0;
        for(int i=0;i<n-1;i++){
            run += nums[i];
            suf-= nums[i];
            if(run >= suf){
                ans++;
            }
        }
        return ans;
    }
};