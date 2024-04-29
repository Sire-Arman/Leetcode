class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bitset<20> x(false);
        for(auto it: nums){
            x^=it;
        }
        // int y = x^k;
        x^=k;
        return x.count();
    }
};