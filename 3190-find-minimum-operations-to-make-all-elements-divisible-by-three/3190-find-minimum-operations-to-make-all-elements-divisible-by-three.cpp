class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = 0;
        for(auto it : nums){
            int rem = it%3;
            n += min(rem , 3-rem);
        }
        return n;
    }
};