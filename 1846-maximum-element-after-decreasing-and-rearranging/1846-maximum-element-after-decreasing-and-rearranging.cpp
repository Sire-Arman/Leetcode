class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
       sort(arr.begin(),arr.end());
        arr[0]=1;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]>1){
                arr[i+1] = arr[i]+1;
            }
        }
        return arr[n-1];
    }
};