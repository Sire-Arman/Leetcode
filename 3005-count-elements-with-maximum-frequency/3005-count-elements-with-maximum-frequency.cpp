class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        int cnt =0;
        int maxi = INT_MIN;
        for(auto it : nums){
            mp[it]++;
            maxi = max(maxi,mp[it]);
        }
        for(auto it : nums){
            if(mp[it] == maxi){
                cnt++;
            }
        }
        return cnt;
    }
};