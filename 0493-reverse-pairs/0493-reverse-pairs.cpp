class Solution {
public:
       void merge(vector<int> &nums, int st,int mid, int end){
           vector<int> temp;
           int left = st;
           int right = mid+1;
           while(left<=mid && right<=end){
               if(nums[left] >= nums[right]){
                   temp.push_back(nums[right++]);
               }
               else{
                   temp.push_back(nums[left++]);
               }  
           }
           while(left<= mid){
                 temp.push_back(nums[left++]);
           }
           while(right<=end){
                 temp.push_back(nums[right++]);
           }
           for(int i=st;i<=end;i++){
               nums[i] = temp[i-st];
           }
       }
        int mergeSort(vector<int> &nums , int st, int end){
            int count=0;
            if(st>=end){
                return count;
            }
            int mid = st + (end-st)/2;
            count+= mergeSort(nums,st,mid);
            count += mergeSort(nums, mid+1, end);
            count += countPairs(nums,st,mid,end);
            merge(nums,st,mid,end);
            return count;
;        }
        int countPairs(vector<int> &nums, int low, int mid , int high){
            int cnt =0;
            int right = mid+1;
            for(int left = low;left<=mid;left++){
               while(right<=high &&  ceil(nums[left]/2.0) > nums[right]){
                   right++;
               } 
            cnt += (right-(mid+1));
            }
            return cnt;
        }
    int reversePairs(vector<int>& nums) {
        int count=0;
       count = mergeSort(nums,0,nums.size()-1);
        return count;
    }
};