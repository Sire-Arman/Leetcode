class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int l =1, r= nums.size()-1;
        while(l<r){
            int mid = l+(r-l)/2;
            int cnt =0;
            for(auto it : nums){
                if(it <= mid) cnt++;
            }
            if(cnt>mid){
                r = mid;
            }
            else l = mid +1;
        }
        return l;
    }
};