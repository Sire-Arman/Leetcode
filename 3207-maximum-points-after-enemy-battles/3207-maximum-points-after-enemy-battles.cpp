class Solution {
public:
    long long maximumPoints(vector<int>& en, int cn) {
        sort(en.begin(), en.end());
        long long pt=0,m=0;
        
        int n = en.size();
        int r = n-1;
        int l = 0;
        long long maxi = cn;
        while(l<=r){
            pt += maxi/en[l];
            m = m>pt?m:pt;
            if(pt == 0) break;
            
            maxi = maxi%en[l] + en[r--];
            // cout<<maxi<<' ';
            
        }
        // cout<<endl;
       
        return m;
    }
};