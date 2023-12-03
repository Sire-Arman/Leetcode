class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int time =0;
        int v1 =p[0][0];
        int v2 =p[0][1];
        for(int i=1;i<p.size();i++){
            v1 = p[i][0]-p[i-1][0];
            v2 = p[i][1]-p[i-1][1];
            time += max(abs(v1),abs(v2));
        }
        return time;
    }
};