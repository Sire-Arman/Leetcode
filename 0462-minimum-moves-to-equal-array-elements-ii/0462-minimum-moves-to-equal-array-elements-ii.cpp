class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median;
        int ans =0;
        int n = nums.size();
        if(n%2 == 0){
            median =(nums[n/2]+nums[n/2-1])/2;
        }
        else median = nums[n/2];
        for(auto it : nums){
            ans += abs(it-median);
        }
        return ans;
    }
};