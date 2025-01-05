class Solution {
public:
long long gcd(long long a, long long b){
    return b==0?a:gcd(b,a%b);
}
    int maxLength(vector<int>& nums) {
        int maxi = -1;
        for(int i =0;i<nums.size();i++){
            long long p = nums[i];
            long long l = nums[i];
            long long g = nums[i];
            long long mp = LLONG_MAX;
            for(int j=i+1;j<nums.size();j++){

                if(p > mp/nums[j]) break;
                p = p*(long long)nums[j] ;
                g = gcd(g,1LL*nums[j]);
                l = (l/gcd(l,nums[j]))*nums[j];
                if(p == g*l) maxi = max(maxi, j-i+1);
            }
        }
        return maxi;
    }
};