class Solution {
public:
   int first(vector<int>& nums, int target ){
       int mini = -1;
        int st =0,end = nums.size()-1;
        while(st<=end){
          int mid = st + (end-st)/2;
            if(nums[mid] == target){
            if(mid == 0 || nums[mid-1]!= target){
                mini = mid;
                break;
            }
                else{
                   end = mid-1; 
                }
        }
        else if(nums[mid]>target){
            end = mid-1;
        }
        else{
            st = mid+1;
        }
            
        }
        
     return mini;   
    }
    int last(vector<int>& nums, int target ){
       int maxi = -1;
        int st =0,end = nums.size()-1;
        while(st<=end){
          int mid = st + (end-st)/2;
            if(nums[mid] == target){
            if(mid == nums.size()-1 || nums[mid+1]!= target){
                maxi = mid;
                break;
            }
                else{
                   st = mid+1; 
                }
        }
        else if(nums[mid]>target){
            end = mid-1;
        }
        else{
            st = mid+1;
        }
            
        }
        
     return maxi;   
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        int st =0,end = nums.size()-1;
        int mini = first(nums, target);
        int maxi = last(nums, target);
        
        
        vector<int> ans(2);
        ans[0] = mini;
        ans[1] = maxi;
        return ans;
    }
};