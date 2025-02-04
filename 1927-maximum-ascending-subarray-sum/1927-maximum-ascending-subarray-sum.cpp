class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0], maxi = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                maxi = max(sum,maxi);
                sum = nums[i];
            }
            else sum += nums[i];
        }
        return max(maxi,sum);
    }
};