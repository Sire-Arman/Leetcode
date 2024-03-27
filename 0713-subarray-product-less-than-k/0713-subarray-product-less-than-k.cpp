class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l =0,r=0;
        int prod =1;
        int cnt =0;
        int n = nums.size();
        int x = 0;
        while(r<n){
            prod*= nums[r];
            if(prod < k){
                r++;
                continue;
            }
            else{
                while(l<=r && prod >= k)
               { prod /= nums[l];
                cnt += (n-r);
                l++;}
            }
            r++;
        }
         
        return n*(n+1)/2 - cnt;
    }
};