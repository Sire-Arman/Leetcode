class Solution {
public:
    int trap(vector<int>& arr) {
      int water =0;
        map<int,pair<int,int>> mp;
        int n = arr.size();
        int leftmax =0,rightmax =0;
        for(int i=0;i<n;i++){
            leftmax = max(arr[i],leftmax);
           mp[i] = make_pair(leftmax,0);
        }
        for(int i=n-1;i>=0;i--){
            rightmax = max(rightmax,arr[i]);
            mp[i].second = rightmax;
        }
        for(int i=0;i<n;i++){
            water += min(mp[i].first,mp[i].second)-arr[i];
        }
        return water;
    }
};