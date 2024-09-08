class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans =0;
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[j]){
                ans += (i-j)*(long long)nums[j];
                j=i;
            }
        }
        long long x = (nums.size()-1-j)*(long long)(nums[j]);
        ans += x;
        return ans;
    }
};