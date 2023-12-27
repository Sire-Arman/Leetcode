class Solution {
public:
    int minCost(string c, vector<int>& t) {
        int time =0;
        if(c.size()==1) return 0;
        for(int i = 0;i<c.size()-1;i++){
            if(c[i]==c[i+1]){
                time += min(t[i],t[i+1]);
                t[i+1] = max(t[i],t[i+1]);
            }
        }
        return time;
    }
};