class Solution {
public:
   void solve (vector<int> nums,vector<int> &temp, vector<vector<int>> &ans,map<int,int> &mp, int i){
        if(temp.size()== nums.size()){
            ans.push_back(temp); 
            return;
        }
       for(int j=0;j<nums.size();j++){
           if(!mp[j]){
           temp.push_back(nums[j]);
           mp[j]=1;
               solve(nums,temp,ans,mp,i+1);
               temp.pop_back();
               mp[j] =0;
           }
       }
        }
    vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> res;
        vector<int> temp;
        map<int,int> mp;
        int i=0;
        solve(nums,temp,res,mp,i);
        return res;
    }
};