class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       unordered_map<int, int> mp;
        int maxi = 0,cnt=0;
        int left =0,right=0;
        while(right<nums.size()){
            mp[nums[right]]++;
            maxi = max(cnt,maxi);
            if(mp[nums[right]]>k){
                while(mp[nums[right]]>k && left<=right){
                    mp[nums[left]]--;
                    left++;
                    cnt--;
                }
            }
            
                cnt++;
            
                right++;

        }

    return max(maxi,cnt);
    }
};