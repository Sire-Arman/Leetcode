class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i1 =-1,i2=-1;
        for(int i= nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                i1 =i;
                break;
            }
        }
        if(i1 == -1){
            reverse(nums.begin(),nums.end());
        }
            else{
              for(int i=nums.size()-1;i>=0;i--){
                  if(nums[i]>nums[i1]){
                      swap(nums[i],nums[i1]);
                       reverse(nums.begin()+i1+1,nums.end());
                      break;
                  }
              }
               
            }
    }
};