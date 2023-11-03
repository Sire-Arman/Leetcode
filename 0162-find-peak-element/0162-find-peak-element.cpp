class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int val = temp[temp.size()-1];
        for(int i=0;i<nums.size();i++){
            if(nums[i] == val){
                return i;
            }
        }
        return -1;
    }
};