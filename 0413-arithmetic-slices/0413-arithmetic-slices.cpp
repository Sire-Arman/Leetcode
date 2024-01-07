class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            int diff = nums[i+1]-nums[i];
            int j=i+1;
            while(j<n){
                if(nums[j]-nums[j-1] != diff){
                   break;
                }
                else j++;
            }
            if(j-i>=3) ans+= j-i-2;
        }
        return ans;
    }
};