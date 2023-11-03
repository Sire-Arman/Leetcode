class Solution {
public:
    int trap(vector<int>& arr) {
      int water =0;
        int n =arr.size();
        int l=0,r=n-1;
        int leftmax=0,rightmax=0;
        while(l<=r){
            if(arr[l]<arr[r]){
                if(arr[l]<leftmax){
                    water+= leftmax-arr[l];
                }
                else{
                    leftmax = arr[l];
                }
                l++;
            }
            else{
                if(arr[r]<rightmax){
                    water+= rightmax-arr[r];
                }
                else{
                    rightmax= arr[r];
                }
                r--;
            }
        }
        return water;
    }
};