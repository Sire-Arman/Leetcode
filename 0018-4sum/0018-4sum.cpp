class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
 vector<vector<int>>  ans;
      if(target <=INT_MIN || target >=INT_MAX){
          return ans;
      }
        set<vector<int>>st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                  set<long long> mp;
                for(int k=j+1;k<n;k++){
                    long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long frth = target - sum;
                    
                    if(mp.find(frth) != mp.end()){
                        vector<int> temp = {nums[i],nums[j],nums[k],(int)frth};
                       sort(temp.begin(),temp.end());
                       st.insert(temp);
                    }
                    mp.insert(nums[k]);  
                }
            }
        }
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};