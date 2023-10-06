class Solution {
public:
    int integerBreak(int n) {
       if(n<=3){
           return n-1;
       }
        if(n%3 == 1){
            int a = n/3;
            return pow(3,a-1)*4;
        }
        if(n%3 == 2){
            int a = n/3;
            return pow(3,a)*2;
        }
        if(n%3 ==0){
            int a =n/3;
            return pow(3,a);
        }
        return 0;
    }
};