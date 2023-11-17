class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int minSum = INT_MIN;
        int i=0,j=n-1;
        while(i<j){
            minSum = max(minSum,nums[i]+nums[j]);
            i++;
            j--;
        }
        return minSum;
    }
};