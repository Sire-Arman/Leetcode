class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>> vp;
        for(int i =0;i<d.size();i++){
            vp.push_back({d[i],p[i]});
        }
        sort(vp.begin(),vp.end());
        sort(w.begin(),w.end());
        int n = w.size(),m=vp.size();
        int j=0,maxi =0,prf = 0;
        for(int i=0;i<n;i++){
            while(j<m && w[i] >= vp[j].first ){
               prf = max(prf,vp[j].second);
                j++;
            }
            maxi += prf;
        }
        return maxi;
    }
};