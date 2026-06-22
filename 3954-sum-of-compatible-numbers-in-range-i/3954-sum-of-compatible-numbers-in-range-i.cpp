class Solution {
public:
    int recursion(int n, int k, int i){
        if(i> n+k) return 0;
        int ans = (i>0 && (n&i) == 0)?i:0;
        return ans + recursion(n,k,i+1);
    }
    int sumOfGoodIntegers(int n, int k) {
        // int ans = 0;
        // for(int i = n-k;i<=n+k;i++){
        //     if(i>0 && (n&i) == 0) {
        //         ans+=i;
        //     }
        // }
        // return ans;
        return recursion(n,k,n-k);
    }
};