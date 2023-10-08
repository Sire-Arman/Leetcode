class Solution {
public:
     void solve (vector<int> nums, vector<vector<int>> &ans, int i){
        if(i== nums.size()){
            if(find(ans.begin(),ans.end(),nums) == ans.end())
            ans.push_back(nums);
            
            return;
        }
        for(int j=i;j<nums.size();j++){
           swap(nums[i],nums[j]);
                solve(nums,ans,i+1);
            swap(nums[i],nums[j]);
            }
        }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
          vector<vector<int>> res;
        int i=0;
        solve(nums,res,i);
        return res;
    }
};