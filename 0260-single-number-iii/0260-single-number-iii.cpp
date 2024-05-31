class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int x=0;
        for(int i=0;i<nums.size();i++){
            x = x^nums[i];
        }
        int i=0,A=0,B=0;
        while(((x>>i)&1)==0)i++;
        for(auto it : nums){
            if(((it>>i)&1)==0){
                A^=it;
            }else{
                B^=it;
            }
        }
        return {A,B};
        
    }
};