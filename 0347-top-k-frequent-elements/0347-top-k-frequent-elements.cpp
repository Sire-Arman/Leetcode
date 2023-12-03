class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> freq;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int fre =1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                freq.push_back({nums[i-1],fre});
                fre=1;
            }
            else fre++;
        }
        vector<int> ans;
        freq.push_back({nums[n-1],fre});
        sort(freq.begin(),freq.end(),cmp);
        for(int i=0;i<k;i++){
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};