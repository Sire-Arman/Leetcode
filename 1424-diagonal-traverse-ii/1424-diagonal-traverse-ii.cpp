class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(auto it: mp){
            vector<int> temp = it.second;
            for(int i = temp.size()-1;i>=0;i--){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};