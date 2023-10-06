class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j = nums.size()-1,k=0;
      while(k<nums.size()){
            if(nums[k] ==0){
                swap(nums[k], nums[i++]);
            }
          k++;
      }
          k=j;
           while(k>=0){
            if(nums[k] ==2){
                swap(nums[k], nums[j--]);
            }
          k--;
        }
    }
};