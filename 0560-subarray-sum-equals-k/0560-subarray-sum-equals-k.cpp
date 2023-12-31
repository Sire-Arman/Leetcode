class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<long,int> mp;
        long sum =0;
        mp[sum] =1;
        int cnt =0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if (mp.find(sum-k) != mp.end()){
                cnt+= mp[sum-k];
            }
        mp[sum]++;
        }
        return cnt;
    }
};