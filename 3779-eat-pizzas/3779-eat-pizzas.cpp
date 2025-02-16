class Solution {
public:
    long long maxWeight(vector<int>& p) {
        long long ans = 0;
        int n = p.size();
        int s = n/4;
        int l=0,r=n-1;
        int odd = ceil((1.0*s)/2);
        s = s-odd;
        sort(p.begin(),p.end());
        while(odd--){
            ans += p[r];
            r--;
            l+=3;
        }
        for(int i=1;i<=s;i++){
                    ans += p[r-1];
                    l+=2;
                    r-=2;
        }
        return ans;
    }
};