class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a1 =0,a2=0;
        for(auto it : nums1) a1 = a1^it;
        for(auto it : nums2) a2 = a2^it;
        int n1 = nums1.size(),n2=nums2.size();
        if(n1&1){
            if(n2&1){
                return a2^a1;
            }
            else{
                return a2;
            }
        }
        else{
            if(n2&1){
                return a1;
            }
            else{
                return 0;
            }
        }
        return 0;
        
    }
};