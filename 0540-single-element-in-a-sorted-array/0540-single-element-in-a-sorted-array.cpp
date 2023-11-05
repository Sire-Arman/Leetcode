class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }
        int st =1,end = n-2;
       
        while(st<=end){
             int mid = st+(end-st)/2;
            if(mid%2==0 && nums[mid+1] == nums[mid] || mid%2 ==1 && nums[mid] == nums[mid-1]){
                st = mid+1;
            }
            else if(mid%2==0 && nums[mid-1] == nums[mid] || mid%2 ==1 && nums[mid] == nums[mid+1]){
                end = mid;
            }
            else{
                return nums[mid];
            }
        }
        return -1;
    }
};