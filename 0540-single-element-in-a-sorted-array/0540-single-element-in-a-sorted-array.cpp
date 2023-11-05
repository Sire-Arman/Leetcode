class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x=0;
        for(auto it :nums){
            x = x^it;
        }
        return x;
    }
};