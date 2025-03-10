class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
      map<int,int> mp;
      long long ans =0,n=nums.size();
      for(int i=0;i<nums.size();i++){
        if(mp[nums[i]-i]){
            ans+=mp[nums[i]-i];
        }
        mp[nums[i]-i]++;
      }
      return (n*(n-1))/2-ans;  
    }
};