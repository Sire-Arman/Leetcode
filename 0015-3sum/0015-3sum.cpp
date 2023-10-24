class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int target =0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int k = i+1;
            int l = n-1;
            while(k<l){
                long long sum = nums[i]+nums[k];
                sum+= nums[l];
                if(sum == target){
                    vector<int> temp = {nums[i],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k] == nums[k-1])k++;
                     while(k<l && nums[l] == nums[l+1])l--;
                }
                else if (sum < target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
        return ans;
    }
};