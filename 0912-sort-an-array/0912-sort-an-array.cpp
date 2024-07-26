class Solution {
public:
    void merge(int l, int mid, int r, vector<int>& nums){
        int l_s = mid-l+1;
        int r_s = r-mid;
        vector<int> left(l_s);
        vector<int> right(r_s);
        for(int i=0;i<l_s;i++){
            left[i] = nums[i+l];
        }
        for(int i=0;i<r_s;i++){
            right[i] = nums[mid+i+1];
        }
        int i=0,j=0, k = l;
        while(i<l_s && j<r_s){
            if(left[i] <= right[j]){
                nums[k++] = left[i++];
            }
            else{
                nums[k++] = right[j++];
            }
        }
        while(i<l_s){
            nums[k++] = left[i++];
        }
        while(j<r_s){
            nums[k++] = right[j++];
        }
    }
    void mergeSort(vector<int>& nums, int l , int r){
        if(l>=r){
            return;
        }
        int mid = l + (r-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(l,mid,r,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};