class Solution {
public:
    int solve(vector<int> &nums, int i, int k, vector<int>& cnt){
        if(i == nums.size()) return 1;
        int a =0,b=0;
        
        if(nums[i]>= k && cnt[nums[i]-k] == 0){
            cnt[nums[i]]++;
            b = solve(nums,i+1,k,cnt);
            cnt[nums[i]]--;
        }
        else if (nums[i] <k){
             cnt[nums[i]]++;
            b = solve(nums,i+1,k,cnt);
            cnt[nums[i]]--;
        }
        int exc = solve(nums,i+1,k,cnt);
        return b+exc;
        
        
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> cnt(1001);
        return solve(nums,0,k,cnt)-1;
    }
};