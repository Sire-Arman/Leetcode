class Solution {
public:
    bool is_prime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
    int maximumPrimeDifference(vector<int>& nums) {
        int l = -1,r=-1;
        for(int i =0;i<nums.size();i++){
            if(is_prime(nums[i])){
                if(l == -1) l = i;
                r = i;
            }
        }
        return r-l;
    }
};