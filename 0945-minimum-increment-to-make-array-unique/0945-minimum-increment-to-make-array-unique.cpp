class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(), nums.end());
        int prev = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
           if(mp[nums[i]]){
               cnt += nums[prev]-nums[i]+1;
               nums[i] = nums[prev]+1;
               prev = i;
           } 
            if(nums[i] > nums[prev]){
                prev = i;
            }
               mp[nums[i]]++;
        }
        return cnt;
    }
};