class Solution {
public:
    void helper(int ind,vector<int>& arr,vector<vector<int>>& ans, vector<int>& sum){
        ans.push_back(sum);
        for(int i=ind;i<arr.size();i++){
            if(i!=ind && arr[i] == arr[i-1]) continue;
            sum.push_back(arr[i]);
            helper(i+1,arr,ans,sum);
            sum.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sum;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        helper(0,nums,ans,sum);
        return ans;
    }
};