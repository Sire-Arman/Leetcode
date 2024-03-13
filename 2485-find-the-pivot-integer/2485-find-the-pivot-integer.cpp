class Solution {
public:
    int pivotInteger(int n) {
        long long sumr = n*(n+1)/2,sqr = sqrt(4*sumr);return (sqr*sqr) == 4*sumr?sqrt(1+4*sumr)/2:-1;
    }
};
