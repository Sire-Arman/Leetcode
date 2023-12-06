class Solution {
public:
    int totalMoney(int n) {
        int rem = n%7;
        int week = n/7;
        int sum =0;
        for(int i=1;i<=week;i++){
            sum += 3.5*(2*i + 6);
        }
        if(rem != 0)
        sum += (rem/2.0)*(2*(week+1)+(rem-1));
        return sum;
    }
};