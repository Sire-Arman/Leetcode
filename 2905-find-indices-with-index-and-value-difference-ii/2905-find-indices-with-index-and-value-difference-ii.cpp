class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int d, int vd) {
        int mini=0,maxi=0;
        for(int i = d;i<nums.size();i++){
            if(nums[i-d]< nums[mini]) mini = i-d;
            if(nums[i-d] > nums[maxi]) maxi = i-d;
            if(nums[i] - nums[mini] >= vd ) return {mini,i};
            if(nums[maxi] - nums[i] >= vd) return {maxi,i};
        }
            
        return {-1,-1};
        }
    
};