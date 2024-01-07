class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<int> ans;
        for(auto it : q){
            priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>> pq;
            for(int i=0;i<nums.size();i++){
                pq.push({nums[i].substr(nums[i].size()-it[1],it[1]),i});
            }
            int n = it[0];
            while(--n){
                pq.pop();
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};