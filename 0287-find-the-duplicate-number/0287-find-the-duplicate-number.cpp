class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int arr[100002] = {0};
        for(int i=0;i<nums.size();i++){
            if(arr[nums[i]]){
                return nums[i];
            }
            arr[nums[i]]++;
        }
        return -1;
    }
};