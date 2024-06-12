class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a =0,b=0;
        int n = nums.size();
        for(auto it : nums){
            if(it==0)a++;
            else if(it == 1) b++;
        }
        for(int i=0;i<n;i++){
            if(a){
                nums[i]=0;
                a--;
            }
            else if(b){
                nums[i] = 1;
                b--;
            }
            else{
                nums[i]=2;
            }
        }
    }
};