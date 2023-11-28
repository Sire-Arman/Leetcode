class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n,0);
        vector<int> suff(n,0);
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+nums[i-1]; 
        }
        for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1]+nums[i+1];
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int val = abs(nums[i]*i-pref[i]) + abs(nums[i]*(n-i-1) - suff[i]);
            ans.push_back(val);
        }
        return ans;
        }
};