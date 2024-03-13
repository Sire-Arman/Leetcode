class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r =n;
        long long suml =0, sumr =0;
        sumr = n*(n+1)/2;
        int ans =-1;
        while(l<=n){
            suml = suml + l;
        // cout<<suml<<' '<<sumr<<endl;
            if(suml == sumr){
                ans = l;
                break;
            }
            sumr -= l;
            l++;
        }
        return ans;
    }
};