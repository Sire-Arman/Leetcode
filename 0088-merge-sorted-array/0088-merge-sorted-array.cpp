class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m ==0){
            nums1 = nums2;
        }
        if(n==0){
            return;
        }
        vector<int> nums(m+n,0);
        int i=0,j=0,index=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                nums[index++] = nums1[i];
                i++;
            }
            else{
                nums[index++] = nums2[j];
                j++;
            }
            
        }
        if(j==n){
            while(i<m){
                nums[index++] = nums1[i++];
            }
            }
            if(i==m){
                while(j<n){
                nums[index++] = nums2[j++];
                }
            }
        nums1 = nums;
    }
};