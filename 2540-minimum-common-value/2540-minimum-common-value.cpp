class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        int i=0,j=0,ans = -1;
        int x=0;
        for(auto it : nums1){
            int ind = lower_bound(nums2.begin(),nums2.end(),it)-nums2.begin();
            
            if(ind != nums2.size() &&  nums2[ind] == it){
                ans = it;
                break;
            }
        }
        return ans;
    }
};