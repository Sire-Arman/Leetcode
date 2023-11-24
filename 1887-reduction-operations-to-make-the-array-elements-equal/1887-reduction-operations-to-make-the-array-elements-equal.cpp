class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans=0,size=1;
        int ind = nums.size()-1;
        sort(nums.begin(),nums.end());
        int val = nums[0];
        while(nums[ind]!=val){
            if(nums[ind] != nums[ind-1]){
                ans+=size;
            }
            ind--;
            size++;
        }
        return ans;
    }
};