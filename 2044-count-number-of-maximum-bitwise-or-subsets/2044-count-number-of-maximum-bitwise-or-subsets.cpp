class Solution {
public:
    int inEx(vector<int>& nums, int i,int curr, int maxi){
        if(i == nums.size()) return 0;
        int ans = (maxi==(curr|nums[i])?1:0);
        ans += inEx(nums,i+1,(curr|nums[i]),maxi);
        ans += inEx(nums,i+1,curr,maxi);
        return ans;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi =0;
        for(auto it : nums){
maxi |= it;}
        return inEx(nums,0,0,maxi);
    }
};