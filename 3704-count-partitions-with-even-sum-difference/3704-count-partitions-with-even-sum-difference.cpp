class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        int run =0;
        int total = accumulate(nums.begin(),nums.end(),0);

        for(int i=0;i<n-1;i++){
            run+= nums[i];
            if(abs(abs(total-run)-run)%2 == 0) {ans++;}
        }
        return ans;
    }
};