class Solution {
public:
    bool isPerfectSquare(int x)
    {
        if (x >= 0) {
            long long sr = sqrt(x);
            return (sr * sr == x);
        }
        return false;
    }
    int pivotInteger(int n) {
        long long sumr = n*(n+1)/2;
        // cout<<sumr<<' '<<sqr<<endl;
        
        if(isPerfectSquare(4*sumr) ){
             return sqrt(1+4*sumr)/2;
            
        }
        else return -1;
    }
};
