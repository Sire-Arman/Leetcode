class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) continue;
            if(nums[i] >= nums.size()-i) {
                if(i==0 || (i>0 && nums[i-1] < nums.size()-i)) return nums.size()-i;
            }
        }
        return ans;
    }
};