class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans =0;
        int run =0,prev =INT_MIN;
        for(int i=0;i<nums.size();i++){
            run = max(run+nums[i],nums[i]);
            prev = max(prev,run);
            ans = max(ans,prev);
        }
        run =0,prev = INT_MAX;
        for(int i=0;i<nums.size();i++){
            run = min(run+nums[i],nums[i]);
            prev = min(prev,run);
            ans = max(ans,abs(prev));
        }
        return ans;
    }
};