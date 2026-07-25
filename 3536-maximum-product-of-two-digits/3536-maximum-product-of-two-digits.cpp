class Solution {
public:
    int maxProduct(int n) {
        int m1=0,m2=0;
        while(n){
            int rem = n%10;
            n/=10;
            if(m1<rem){
                m2 = m1;
                m1 = rem;
            }
            else if (m2<=rem){
                m2 = rem;
            }
        }
        return m1*m2;
    }
};