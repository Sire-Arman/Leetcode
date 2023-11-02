class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int val = nums[0];
        int cnt=nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i] == val){
                nums[i] = INT_MAX;
                cnt--;
            }
            else{
                val = nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        return cnt;
        
    }
};