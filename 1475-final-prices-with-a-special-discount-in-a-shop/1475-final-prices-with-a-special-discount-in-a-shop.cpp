class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        vector<int> ans(p.size());
        for(int i=0;i<p.size()-1;i++){
            for(int j= i+1;j<p.size();j++){
                if(p[j]<=p[i]){
                    ans[i] = p[i]-p[j];
                    break;
                }
                else ans[i] = p[i];
            }
        }
        ans[p.size()-1] = p[p.size()-1];
        return ans;
    }
};