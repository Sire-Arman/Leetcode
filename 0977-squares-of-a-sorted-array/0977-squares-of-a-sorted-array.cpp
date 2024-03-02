class Solution {
public:
    static bool cmp(int& a, int& b){
        return (abs(a) < abs(b));
    }
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        for(auto &it : nums){
            it = it*it;
        }
        return nums;
    }
};