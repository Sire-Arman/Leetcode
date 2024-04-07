class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0,j=1;
        int n = nums.size();
        int maxi = 0;
        while(j<n){
            if(nums[j] <= nums[j-1]){
                maxi = max(maxi, j-i);
                i = j;
            }
            j++;
        }
        if(j == n) maxi = max(j-i,maxi);
        int mini = 0;
        j = n-2,i=n-1;
        while(j>=0){
            if(nums[j] <= nums[j+1]){
                mini = max(mini, i-j);
                i = j;
            }
            j--;
        }
        if(j < 0) mini = max(i-j,mini);
        return max(maxi,mini);
    }
};