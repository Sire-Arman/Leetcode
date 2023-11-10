class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int minSum = INT_MAX;
        int minRes = 0;
        for(int left=0;left<n-2;left++){
            int a = left+1;
            int b=  n-1;
            
            while(a<b){
                int sum = nums[left]+nums[a]+nums[b];
                if(sum == target){
                    return sum;
                }
                else if(sum>target){
                    b--;
                }
                else{
                    a++;
                }
                if(minSum>abs(target-sum)){
                    minSum = abs(target-sum);
                    minRes = sum;
                }
            }
        }
        return minRes;
    }
};