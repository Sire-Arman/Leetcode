class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = speed.size();
        vector<double> time(n,0.0);
        for(int i=0;i<n;i++){
            time[i] = dist[i]/(speed[i]+0.0);
        }
        sort(time.begin(),time.end());
        for(int i=0;i<n;i++){
            if(time[i]<=i){
                return i;
            }
        }
        return n;
    }
};