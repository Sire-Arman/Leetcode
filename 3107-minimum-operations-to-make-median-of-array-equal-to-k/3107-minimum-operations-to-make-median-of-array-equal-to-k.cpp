class Solution {
public:
    int mod = 1e9+7;
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ind = nums.size()/2;
        long long ans = 0;
        if(k <= nums[ind]){
            for(int i = ind;i>=0;i--){
                if(nums[i] > k)
                ans = (ans + (nums[i]-k));
                else break;
            }   
        }
        else{
            for(int i = ind;i<nums.size();i++){
                if(nums[i] < k)
                ans = (ans + (k - nums[i]));
                else break;
            }   
        }
        return ans;
    }
};