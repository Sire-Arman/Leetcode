class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum =0,n=nums.size();
        int cnt=0,run =0;
        map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            run += nums[i];
            int x = run%k;
            if(x<0) x+=k;
            if(mp[x]){
                cnt += mp[x];
            }
                mp[x]++;
        }
        return cnt;
    }
};