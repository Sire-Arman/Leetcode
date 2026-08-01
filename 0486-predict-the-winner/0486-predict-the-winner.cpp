class Solution {
public:
    int solve(vector<int>& nums,int l, int r, int p, int turn){
        if(l==r){
            return p += turn*nums[l];
        }
        int ans;
        if(turn==1){
            ans = max(nums[l] + solve(nums,l+1,r,p,turn*-1),nums[r] + solve(nums,l,r-1,p,turn*-1));
        }
        else{
            ans = min(-nums[l]+solve(nums,l+1,r,p,turn*-1),-nums[r] + solve(nums,l,r-1,p,turn*-1));
        }
        return ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums,0,nums.size()-1,0,true)>=0;
    }
};