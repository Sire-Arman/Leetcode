class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int r =0,l=-1;
        int cur_l =0,next_r=0;
        int n = nums.size();
        int ans =0;
        if(k>nums.size()) return 0;
        int cnt =0;
        
        while(r<n){
            if(nums[r]&1){
                cnt++;
            }
            if(cnt == k) break;
            r++;
        }
        if(r==n) return 0;
        while(r<n){
            l++;
            while(l<n && nums[l]%2 != 1){
                l++;
                cur_l++;
            }
            r++;
            while(r<n && nums[r]%2!=1){
                next_r++;
                r++;
            }
           
            ans += cur_l+next_r+1 + cur_l*next_r;
            next_r=0;
            cur_l =0;
            
        }
        return ans;
    }
};