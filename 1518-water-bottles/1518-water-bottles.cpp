class Solution {
public:
    int numWaterBottles(int nb, int ne) {
        int d = 0;
        while(nb > 0) {
            d += nb<ne?nb:ne;
            nb-= ne;
            nb++;
        }
        return d;
    }
};