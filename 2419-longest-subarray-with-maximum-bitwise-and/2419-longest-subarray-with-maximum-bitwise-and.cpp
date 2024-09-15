class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int x = *max_element(nums.begin(),nums.end());
        int len =0,tmp=0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == x) tmp++;
            else {
                len = max(len , tmp);
                tmp =0;
            }
        }
        return max(len,tmp);
    }
};