class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        int cnt =0;
        for(auto it : mp){
            int num = it.second;
            
            while(num >=2 && num%3 != 0){
                num-=2;
                cnt++;
            }
            if(num ==1) return -1;
            if(num%3 == 0) cnt+=num/3;
        }
        
        return cnt;
    }
};