class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int m1 = 0,m2 =0,m3=0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        m1 = nums[0]*nums[1]*nums[n-1];
        m2 = nums[n-3]*nums[n-2]*nums[n-1];
        m3 = nums[0]*nums[1]*nums[2]; 
        return max({m1,m2,m3});
    }
};