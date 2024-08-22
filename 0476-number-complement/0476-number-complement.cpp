class Solution {
public:
    int findComplement(int num) {
        int power =0;
        int ans = 0;
        while(num){
            int x = num%2;
            if(x==0){
                ans += pow(2,power);
            }
            power++;
            num/=2;
        }
        return ans;
    }
};