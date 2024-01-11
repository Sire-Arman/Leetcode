class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> known(n+1);
        vector<int> forgot(n+1);
        int share =0;
        int secret =1;
        int MOD = 1e9+7;
        known[delay] = forgot[forget] = 1;
        for(int i=0;i<n;i++){
            share += known[i];
            share %= MOD;
            
            share -= forgot[i];
            if(share<0) share+= MOD;
            secret += share;
            secret %= MOD;
            
            secret -= forgot[i];
            if(secret<0) secret+= MOD;
            
            if((i+delay)<n) known[i+delay] += share;
            if((i+forget)<n) forgot[i+forget] += share;   
        }
        return secret;
    }
};