class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j= nums.size()-1;
        int x = -1;
        while(i<j){
            if(nums[i]>=0 || nums[j]<=0) break;
            else if(~nums[i]+1 > nums[j]) i++;
            else if (~nums[i]+1 < nums[j]) j--;
            else {x = nums[j]; break;}
        }
        return x;
    }
};