class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        map<int,int> mp;
        long long summ = 0;
        for(auto it : nums){
            summ+=it;
            mp[it]++;
        }
        int ans = INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            mp[nums[i]]--;
            int val = summ - 2*nums[i];
            if(mp[val] > 0 ){
                ans = max(ans, val);
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};