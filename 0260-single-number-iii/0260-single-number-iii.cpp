class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2){
            return nums;
        }
        vector<int> ans;
       map<int,int> mp;
        for(auto it : nums){
            if(mp[it]){
                mp[it]--;
            }
            else{
                mp[it]++;
            }
        }
        for(auto it : mp){
            if(it.second){
                ans.push_back(it.first);
            }
        }
return ans;
        
    }
};