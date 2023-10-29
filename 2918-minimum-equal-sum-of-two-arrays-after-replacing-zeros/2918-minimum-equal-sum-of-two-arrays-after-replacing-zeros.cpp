class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long zero1 = 0,zero2=0;
        long long s1 =0,s2=0;
        for(auto it: nums1){
            if(it == 0){
                zero1++;
            }
            s1+=it;
        }
        s1+=zero1;
        for(auto it: nums2){
            if(it == 0){
                zero2++;
            }
            s2+=it;
        }
        s2+=zero2;
        if(s1<s2 && zero1==0 || s1>s2 && zero2==0){
            return -1;
        }
        return max(s1,s2);
    }
};