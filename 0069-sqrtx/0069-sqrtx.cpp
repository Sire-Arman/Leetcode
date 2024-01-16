#define a_int long long int
class Solution {
public:
    int mySqrt(int x) {
        a_int s =0,e=x;
        a_int mid ;
        a_int temp = -1;
        while(s<=e){
            mid = s + (e-s)/2;
            if(mid*mid > x){
                e = mid-1;
            }
            else if( mid* mid <x){
                temp = mid;
                s = mid+1;
            }
            else if(mid*mid == x) {
                return (int)mid;
            }
        }
        
        return temp;
    }
};