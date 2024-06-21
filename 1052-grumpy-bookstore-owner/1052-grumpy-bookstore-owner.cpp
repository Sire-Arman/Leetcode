class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int k) {
        int l=0,r=0;
        int n = c.size();
        int maxi=0,tsum=0;
        while(r<k){
            if(g[r]==1) tsum +=c[r];
            r++;
        }
        // cout<<tsum<<endl;
        while(r<n){
            if(r-l > k-1){
                maxi = max(maxi,tsum);
                if(g[l]==1) tsum-= c[l];
                l++;
            }
            if(g[r]==1) tsum+=c[r];
            r++;
        }
        maxi = max(maxi,tsum);
        // cout<<maxi<<endl;
        for(int i=0;i<n;i++){
            if(!g[i]) maxi+=c[i];
        }
        return maxi;
    }
};