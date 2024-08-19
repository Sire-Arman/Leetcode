class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int sm = arr[0][0];
        int lr = arr[0].back();
        int maxi=0; 
            for(int i=1;i<arr.size();i++){
            maxi = max(maxi,abs(sm-arr[i].back()));
            maxi = max(maxi,abs(lr-arr[i][0]));
                       sm = min(sm,arr[i][0]);
                       lr = max(lr, arr[i].back());
            }
        return maxi;
    }
};