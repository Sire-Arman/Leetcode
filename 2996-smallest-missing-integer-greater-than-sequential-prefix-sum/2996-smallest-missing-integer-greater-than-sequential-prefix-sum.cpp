class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int len =1,maxLen=0,sum=nums[0];
        int ans = -1;
        map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]+1){
                sum+=nums[i];
                len++;
            }
            else if(nums[i] != nums[i-1]+1){
                // cout<<i<<' '<<sum<<endl;
                if(len >= maxLen){
                    int t = sum;
                    while(mp.count(t)) t++;
                    ans = len>maxLen?t:max(ans,t);
                    maxLen = len;
                    return ans;
                }
                len=1;
                sum = nums[i];
            }
        }
        // cout<<ans<<endl;
        if(len>=maxLen){
            int t = sum;
            while(mp.count(t)) t++;
            ans = len>maxLen?t:max(ans,t);
            maxLen = len;
        }
        return ans;
    }
};