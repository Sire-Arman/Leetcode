class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> mp;
        if(nums.size() == 0){
            return 0;
        }
        for(auto it : nums){
            mp.insert(it);
        }
        int len =1;
        int cnt =1;
        for(auto it : mp){
            if(mp.find(it-1) == mp.end()){
                int next = it+1;
                while(mp.find(next) != mp.end()){
                    cnt++;
                    next++;
                }
            }
                len = max(len , cnt);
                cnt=1;
        }
        return len;
    }
};