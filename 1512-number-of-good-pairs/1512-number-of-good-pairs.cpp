class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0,i=0,n= nums.size();
        for(int i=0;i<n;i++){
            for(int j= i+1;j<n;j++){
                if(i<j && nums[i] == nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};