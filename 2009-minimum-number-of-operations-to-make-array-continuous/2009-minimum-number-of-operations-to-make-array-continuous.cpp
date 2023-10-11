class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int count =1;
        map<int,bool> mp;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]){
                nums[i] = INT_MIN;
            }
            else
            mp[nums[i]] = true;
        }
        sort(nums.begin(),nums.end());
//         duplication removed
        int minCount =0, cnt =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != INT_MIN){   
            int ub = nums[i]+nums.size()-1;
            int index = upper_bound(nums.begin(),nums.end(),ub)-nums.begin();
            index--;
            minCount = max(minCount, index-i+1);
        }
            }
        return nums.size()-minCount;
    }
};