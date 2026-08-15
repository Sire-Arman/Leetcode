class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        bool nonZero = false;
        int ans = nums.size();
        for(int i=0;i<nums.size();i++){
            nonZero = (nonZero | (nums[i]>0));
            xr^=nums[i];
        }
        if(xr != 0) return ans;
        if(nonZero){
            return ans-1;
        }
        return 0;
    }
};