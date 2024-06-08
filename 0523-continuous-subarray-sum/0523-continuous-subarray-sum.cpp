class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return false;
        int cum =0;
        map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            cum += nums[i];
            int rem = cum%k;
            
            if(mp.count(rem)){
                if(i-mp[rem] > 1){
                    return true;
                } 
            }
            else{
                mp[rem] =i;
            }
        }
        return false;
    }
};