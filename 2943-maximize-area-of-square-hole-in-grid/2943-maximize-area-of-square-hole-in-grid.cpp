class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int hdis = 1,vdis =1;
        int cnth=1,cntv=1;
        
        for(int i=1;i<hBars.size();i++){
            if(hBars[i] == (hBars[i-1]+1)){
                cnth++;
            }
            else{
                cnth=1;
            }
            hdis = max(hdis,cnth);
        }
        for(int i=1;i<vBars.size();i++){
            if(vBars[i] == (vBars[i-1]+1)){
                cntv++;
            }
            else{
                cntv =1;
            }
            vdis = max(vdis,cntv);
        }
        hdis = min(hdis,vdis);
        return ++hdis*hdis;
    }
};