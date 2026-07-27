class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int a = -1,b=-1;
        for(auto it : nums){
            if(it>=a){
                b=a;
                a=it;
            }
            else if(it>b){
                b = it;
            }
        }
        return (a-1)*(b-1);
    }
};