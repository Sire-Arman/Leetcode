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
        int x =0;
       for(auto it : nums){
           x = x|it;
       } 
        int n = pow(2,nums.size()-1);
        // // cout<<x;
        // int s = static_cast<int>(ceil(log2(x)));
        // // cout<<s;
        // int d =0,sum=0;
        // while(s--){
        //     if(x>>1){
        //         sum += pow(2,d);
        //     };
        //     d++;
        //     // x = x>>1;
        // }
        return x*n;
        
    }
};