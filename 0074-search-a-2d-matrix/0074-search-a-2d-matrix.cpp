class Solution {
public:
    bool binary(vector<int> arr,int target){
        int st=0,end=arr.size()-1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(arr[mid] == target){
                return true;
            }
            else if(arr[mid]>target){
                end = mid-1;
            }
            else{
                st= mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col = matrix[0].size();
        if(target<matrix[0][0] || target>matrix[row-1][col-1] ){
            return false;
        }
        for(int i=0;i<matrix.size();i++){
            if(target<=matrix[i][col-1]){
                return binary(matrix[i],target);
            }
        }
        return false;
    }
};