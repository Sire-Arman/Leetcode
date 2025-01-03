class Solution {
public:
int MOD = 1e9+7;
    // long long fact(int a){
    //     if(a<=1) return 1;
    //     return 1LL*(a*fact(a-1))%MOD;
    // }
    long long expo(long long a, int b){
        if(b==0) return 1;
        if(b==1 || a==0) return a;
        long long ans = 1;
        while(b>0){
            if(b&1){
            ans = (ans*a)%MOD;
            }
            a = (a*a)%MOD;
            b/=2;
        }
        return ans;
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> f(n+1,1);
        for(int i=2;i<=n;i++){
            f[i] = (f[i-1]*i)%MOD;
        }
        long long x = f[n-1];
        long long y = expo(f[k],MOD-2);
        long long z = expo(f[n-k-1],MOD-2);
        x = ((x*y)%MOD*z)%MOD;
        long long a = expo(m-1,n-k-1);
        x = (x*a)%MOD;
        x = (x*m)%MOD;
        return x;
        
    }
};