class Solution {
public:

long long helper(vector<int>& nums, int i, long long m, long long d,vector<int> cond){
    if(cond[3]==4 && m == d) return 1;
    if(i >= nums.size()) return 0;
    long long ans =0;
    if(cond[0]==1){
        if(cond[1]==1){
            ans+=helper(nums,i+1,m,d,cond);
            cond[0]=0;
            cond[1]=0;
            cond[2]=1;
            cond[3]+=1;
             ans += helper(nums,i+1,m*nums[i],d,cond);
        }
        else{
            ans+=helper(nums,i+1,m,d,cond);
            cond[0]=0;
            cond[1]=1;
            cond[2]=0;
            cond[3]+=1;
             ans += helper(nums,i+1,m,d*nums[i],cond);
        }
    }
    else{
        cond[0]=1;
        ans += helper(nums,i+1,m,d,cond);
    }
    return ans;

}
    long long numberOfSubsequences(vector<int>& nums) {
    unordered_map<double, long long> freq;
    long long ans = 0;
    for(int r = 4; r < nums.size(); ++r){
        for(int p = 0, q = r - 2; p < q-1; ++p) freq[(double)nums[p]/(double)nums[q]]++;
        for(int s = r + 2; s < nums.size(); ++s) ans += freq[(double)nums[s]/(double)nums[r]];
    }
    return ans;
}
};