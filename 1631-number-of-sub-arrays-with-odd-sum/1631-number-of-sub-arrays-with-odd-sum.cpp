class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9+7;
        vector<int> dpe(n),dpo(n);
        if(arr[n-1]&1){
            dpo[n-1] = 1;
        }
        else{
            dpe[n-1] =1;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]&1){
                dpo[i] = (dpe[i+1]+1)%MOD;
                dpe[i] = dpo[i+1];
            }
            else{
                dpe[i] = (1+dpe[i+1])%MOD;
                dpo[i] = dpo[i+1];
            }
        }
        long long ans =0;
        for(auto &it : dpo){
            ans = (ans+it)%MOD;
        }
        return ans;
    }
};