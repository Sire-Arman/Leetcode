class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = nums[0],second =0, index=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>largest){
                second = largest;
                largest = nums[i];
                index =i;
            }
            else if(nums[i]>second){
                second = nums[i];
            }
        }
        if(largest-second >= second){
            return index;
        }
        return -1;
    }
};