class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0,r=0;
        int sum =0,ans=0;
        int n = nums.size();
        map<int,int> freq;
        freq[0] = 1;
        while(r<n){
          sum += nums[r];
            if(freq.find(sum-goal) != freq.end()){
                ans += freq[sum-goal];
            }
            freq[sum]++;
            r++; 
        }
        return ans;
    }
};