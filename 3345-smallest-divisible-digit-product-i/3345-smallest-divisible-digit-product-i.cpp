class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int temp = n,prod =1;
            while(temp){
                int rem = temp%10;
                temp/=10;
                if(rem==0){
                    prod = 0;
                    break;
                }
                else prod*=rem;
            }
            if(prod == 0 || prod%t == 0) return n;
            n++;
        }
        return -1;
    }
};