class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int a = INT_MIN, b=INT_MIN;
        int c = INT_MAX, d=INT_MAX;
        for(auto it : nums){
            if(it>a){
                b=a;
                a=it;
            }
            else if(it>b){
                b = it;
            }
            if(it<c){
                d=c;
                c=it;
            }
            else if(it<d){
                d=it;
            }
        }
        return (a*b)-(c*d);
    }
};