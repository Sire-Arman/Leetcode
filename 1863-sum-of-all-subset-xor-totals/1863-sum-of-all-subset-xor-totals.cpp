class Solution {
public:
    int solve(vector<int>& nums, int ind,int c){
        if(ind == nums.size()) return c;
        int ans1 =0,ans2=0;
        ans1 = solve(nums,ind+1,c^nums[ind]);
        // cout<<ans<<' '; 
        ans2 = solve(nums,ind+1,c);
        
        return ans1+ans2;
    }
    int subsetXORSum(vector<int>& nums) {
       return solve(nums,0,0);
        
        
    }
};