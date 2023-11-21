class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int val =nums[i];
            int revr =0;
            while(val){
                revr = revr*10 + val%10;
                val/=10;
            }
            nums[i] = (nums[i]-revr);
        }
        int cnt=0;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]){
                cnt = (cnt+mp[nums[i]])%1000000007;
            }
            mp[nums[i]]++;
        }
        
        
        return cnt;
    }
};