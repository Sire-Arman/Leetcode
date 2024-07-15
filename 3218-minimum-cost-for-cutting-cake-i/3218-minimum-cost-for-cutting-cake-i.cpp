class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int hor =1,ver =1;
        int ans =0;
        int i = h.size()-1,j = v.size()-1;
        while(i>=0 && j>=0){
            if(h[i] >= v[j]){
                ans += h[i]* ver;
                i--;
                hor++;
            }
            else{
                ans += v[j]* hor;
                j--;
                ver++;
            }
        }
        while(i>=0){
            ans += h[i]*ver;
            i--;
            hor++;
        }
        while(j>=0){
            ans += v[j]*hor;
            j--;
            ver++;
        }
        return ans;
    }
};