class Solution {
public:
    int numberOfMatches(int n) {
        int cnt=0;
        while(n!=1){
            if(n%2==0){
               n/=2; 
                cnt+=n;
            }
            else{
                n = n/2+1;
                cnt+= n-1;
            }
        }
        return cnt;
    }
};