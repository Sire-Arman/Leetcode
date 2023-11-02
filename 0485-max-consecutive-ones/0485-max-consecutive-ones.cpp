class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len =0,max_len =0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==1){
                len++;
            }
            else{
                max_len = max(max_len,len);
                len=0;
            }
            i++;
        }
        return max(max_len,len);
    }
};