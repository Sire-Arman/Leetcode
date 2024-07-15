class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c) {
        if(c.size()<3) return 0;
        int cnt =0;
        int n =c.size();
        for(int i=0;i<n;i++){
            if(c[i] != c[i-1<0?n-1:i-1] && c[i] != c[i+1>=n?0:i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};