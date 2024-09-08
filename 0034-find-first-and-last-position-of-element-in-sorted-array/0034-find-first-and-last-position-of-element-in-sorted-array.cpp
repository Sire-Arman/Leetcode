class Solution {
public:
    int f(int t, vector<int>& nums){
        if(nums.size()==1){
            if(t==nums[0]) return 0;
            return -1;
        }
        int f = -1;
        int l=0,r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==t){
                f = mid;
            }
            if(nums[mid]>= t){
                r = mid-1;
            }
            else l = mid +1;
        }
        return f;
        
    }
    int l(int t, vector<int>& nums){
        if(nums.size()==1){
            if(t==nums[0]) return 0;
            return -1;
        }
        int f = -1;
        int l=0,r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==t){
                f = mid;
            }
            if(nums[mid]<= t){
                l= mid+1;
            }
            else r = mid-1;
        }
        return f;
        
    }
    vector<int> searchRange(vector<int>& nums, int t) {
        return {f(t,nums), l(t,nums)};
    }
};