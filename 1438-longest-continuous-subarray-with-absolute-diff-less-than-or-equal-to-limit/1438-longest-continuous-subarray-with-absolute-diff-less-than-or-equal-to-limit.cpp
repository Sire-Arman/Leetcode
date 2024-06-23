class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       deque<int> inc;
        deque<int> dsc;
        int n = nums.size();
        int left=0,ans=0;
        for(int i=0;i<n;i++){
            while(!inc.empty() && nums[i]<inc.back()) inc.pop_back();
            inc.push_back(nums[i]);
            
            while(!dsc.empty() && nums[i] > dsc.back()) dsc.pop_back();
            dsc.push_back(nums[i]);
            
            if(dsc.front()-inc.front() >limit){
                if(dsc.front() == nums[left]){
                    dsc.pop_front();
                }
                if(inc.front() == nums[left]) inc.pop_front();
                left++;
            }
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};