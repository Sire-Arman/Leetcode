class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int l =0,r=0;
        int n = s.size();
        long long s1=0,s2=0;
        int maxi = INT_MIN;
        while(r<n){
                 s1+=abs(s[r]-t[r]);
            while(s1 >k && l<r){
                s1 -= abs(s[l]-t[l]);
                l++;
            }
            if(s1<=k)
                maxi = max(maxi, r-l+1);
           
            r++;
        }
        if(maxi == INT_MIN) return 0;
        return max(maxi,r-l);
    }
};