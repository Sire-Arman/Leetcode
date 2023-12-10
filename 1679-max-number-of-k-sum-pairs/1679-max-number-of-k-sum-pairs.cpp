class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
       int left =0,right = n-1;
        int cnt=0;
        sort(nums.begin(),nums.end());
        while(left<right){
            if(nums[left] + nums[right] == k){
                left++;
                right--;
                cnt++;
            }
            else if (nums[left] + nums[right] > k){
                right--;
            }
            else{
                left++;
            }
        }
        return cnt;
    }
};