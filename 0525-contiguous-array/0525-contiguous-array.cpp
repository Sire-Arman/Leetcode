class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int x =0;
        int len = 0,maxi = 0;
        int n = nums.size();
        vector<int> hashp (n+1,-2);
        vector<int> hashn (n+1,-2);
        hashp[0] = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0) x--;
            else x++;
            if(x>=0){
                if(hashp[x] != -2){
                    maxi = max(i-hashp[x],maxi);
                }
                else {
                    hashp[x] = i;
                }
            }
            else{
                if(hashn[abs(x)] != -2){
                    maxi = max(maxi,i-hashn[abs(x)]);
                }
                else{
                    hashn[abs(x)] = i;
                }
            }
        }
        return maxi;
    }
};