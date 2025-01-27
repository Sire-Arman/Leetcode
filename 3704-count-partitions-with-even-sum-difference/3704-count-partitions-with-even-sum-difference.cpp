class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        vector<int> pref(n+1);
        pref[0] = nums[0];
        int total = nums[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+nums[i];
            total += nums[i];
        }
        for(int i=0;i<n-1;i++){
            if(abs(abs(total-pref[i])-pref[i])%2 == 0) {ans++;}
        }
        return ans;
    }
};