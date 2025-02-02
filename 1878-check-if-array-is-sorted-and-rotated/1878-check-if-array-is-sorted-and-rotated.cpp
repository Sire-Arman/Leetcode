class Solution {
public:
    bool check(vector<int>& nums) {
        int ch =0,m=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                if(ch) return false;
                ch++;
            }
        }
        return !(ch && nums[0]<nums[nums.size()-1]);
    }
};