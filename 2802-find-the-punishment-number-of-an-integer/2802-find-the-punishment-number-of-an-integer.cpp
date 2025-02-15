class Solution {
public:
bool sumCheck(int t, int num){
    if(t==0 && num==0) return 1;
    if(t<0) return 0;
    int temp = num,div=10;
    bool ans = false;
    while((temp*10)/div){
        int rem = temp%div;
        if (sumCheck(t-rem,temp/div)) return true;
        div*=10;
    }
    return ans;
}

    int punishmentNumber(int n) {
        int ans =0;
        for(int i=1;i<=n;i++){
            if(sumCheck(i,i*i)) {ans += i*i;}
        }
        return ans;
    }
};