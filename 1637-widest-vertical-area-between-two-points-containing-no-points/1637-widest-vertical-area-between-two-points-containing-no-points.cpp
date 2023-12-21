class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        for(auto it : points){
            x.push_back(it[0]);
        }
        int maxi = INT_MIN;
        sort(x.begin(),x.end());
        for(int i=1;i<x.size();i++){
            int diff = abs(x[i]-x[i-1]);
            maxi = max(diff,maxi);
        }
        return maxi;
    }
};