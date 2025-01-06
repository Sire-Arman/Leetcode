class Solution {
public:
    long long maximumCoins(vector<vector<int>>& c, int k) {
        sort(c.begin(),c.end());
        int n = c.size();
        long long res =0, full =0,part =0;
        for(int i=0,j=0;i<n;i++){
            int l = c[i][0];
            int r = c[i][1];
            while(j<n && c[j][1] - l +1 <=k){
                full += 1LL*(c[j][1]-c[j][0]+1)*c[j][2];
                j++;
            }
            res =max(res,full);
               if(j<n) {part = 1LL*(k-c[j][0]+l)*c[j][2];
            res = max(res,full + (part<0?0:part));}
            full -= 1L*(c[i][1]-c[i][0]+1)*c[i][2];
        }
        full =0;
        for(int i=n-1,j=n-1;i>=0;i--){
            int r = c[i][1];
            int l = c[i][0];
            while(j>=0 && r-c[j][0]+1<=k){
                full += 1LL*(c[j][1]-c[j][0]+1)*c[j][2];
                j--;
            }
            res  = max(res,full);
            if(j>=0){ part = 1LL*(c[j][1]-r+k)*c[j][2];
            res = max(res,full + (part<0?0:part));}
            full -= 1LL*(c[i][1]-c[i][0]+1)*c[i][2];
        }
        return res;
    }
};