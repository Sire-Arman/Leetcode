class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j= nums.size()-1;
        int x = -1;
        while(i<j){
            if(nums[i]>=0 || nums[j]<=0) break;
            else if(-1*nums[i] > nums[j]) i++;
            else if (-1* nums[i] < nums[j]) j--;
            else {x = nums[j]; break;}
        }
        return x;
    }
};