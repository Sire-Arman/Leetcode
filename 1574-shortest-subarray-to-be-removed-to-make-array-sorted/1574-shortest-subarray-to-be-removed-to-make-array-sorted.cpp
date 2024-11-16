class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if(arr.size()==1) return 0;
        int i=0,j=arr.size()-1;
        while(j>0 && arr[j] >= arr[j-1]){
            j--;
        }
        int mini = j;
        if(j ==0) return 0;
        while(i<j && (i==0 || arr[i] >= arr[i-1])){
            while(j<arr.size() && arr[i] > arr[j]) j++;
            mini = min( mini, j-i-1);
            i++;
        }
        return mini;
    }
};