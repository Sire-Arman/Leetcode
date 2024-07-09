class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double wt = 0;
        int idle =0;
        for(auto it : c){
            int wait = it[1];
            int x =0;
            if(idle >= it[0]){
                wait += idle-it[0];
                x = idle-it[0];
            }
                idle = it[0] + it[1]+x;
            wt += wait;
        }
        return wt/c.size();
    }
};