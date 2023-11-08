class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy){
            return (t!=1);
        }
        int min1= abs(fy-sy);
        int min2 = abs(fx-sx);
        return ( max(min1,min2)<=t);
    }
};