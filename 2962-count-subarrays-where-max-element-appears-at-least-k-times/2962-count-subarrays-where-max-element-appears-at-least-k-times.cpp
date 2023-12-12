class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int el = *max_element(nums.begin(),nums.end());
        int i =0,j =0;
        int cnt=0;
        long long ans=0;
        while(j<nums.size()){
            if(nums[j] == el){
                cnt++;
            }
            if(cnt>=k){
                while(cnt >=k){
                    ans += nums.size()-j;
                    if(nums[i] == el){
                        cnt--;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};