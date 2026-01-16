class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(auto& it: nums){
            mp[it[0]]++;
            mp[it[1]]--;
        }
        int l =0;
        int run_sum = 0;
        int sum = 0;
        for(auto& it: mp){
            if(run_sum == 0){
                l = it.first;
            }
            run_sum+=it.second;
            if(run_sum <= 0){
                sum += (it.first-l+1);
            }
        }
        return sum;
    }
};