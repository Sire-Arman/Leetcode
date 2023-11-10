class Solution {
public:
    int minOperations(int n) {
       if(n%2==0){
           int sum=1;
           for(int i=0;i<=n/2;i++){
               sum += n - (2*i+1);
           }
           return sum;
           
       }
            n/=2;
            return n*(n+1);
    }
};