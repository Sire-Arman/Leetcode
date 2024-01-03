class Solution {
public:
    long long lcm(long long a , long long b){
        return (a*b)/__gcd(a,b);
    }
    int calculate(int cnt, long long d1, long long d2=1){
        long long lc = lcm(d1,d2);
        return cnt + cnt/(lc-1)-(cnt%(lc-1)?0:1);
    }
    int minimizeSet(int d1, int d2, int c1, int c2) {
        auto calculateLambda = [&](int cnt, long long d1, long long d2 = 1) {
            long long lc = lcm(d1, d2);
            return cnt + cnt / (lc - 1) - (cnt % (lc - 1) ? 0 : 1);
        };
        return max({calculateLambda(c1,d1),
                    calculateLambda(c2,d2),
                    calculateLambda(c1+c2,d1,d2)});
    }
};