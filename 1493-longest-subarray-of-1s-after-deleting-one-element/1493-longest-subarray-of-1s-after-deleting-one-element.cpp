class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero =1;
        int cnt=0,index=0;
        int n = nums.size();
        int left =0,right=0;
        int cnt1 =0,cnt2=0;
        int maxi = 0;
        int flag = 0;
        for(auto it: nums){
            if(it == 0){
                flag =1;
                break;
            }
        }
        if(!flag){
            return n-1;
        }
        for(int i=0;i<n;i++){
            if( i==0  && nums[i] == 0 || i== n-1 && nums[i]==0) continue;
            if(cnt1+cnt2 > maxi){
                maxi = cnt1+cnt2;
            }
            if(nums[i] == 1){
                cnt2++;
            }
            else if(nums[i-1] == 1 &&  nums[i+1] == 1){
                cnt1 = cnt2;
                cnt2=0;
            }
            else {
            cnt1=0;
            cnt2=0;
            }
        }
        return max(maxi,cnt1+cnt2);
    }
};