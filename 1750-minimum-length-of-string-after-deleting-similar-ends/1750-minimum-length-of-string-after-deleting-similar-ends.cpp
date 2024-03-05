class Solution {
public:
    int minimumLength(string s) {
        int l=0,r=s.size() -1;
        while(l < r){
            if(s[l] != s[r]){
                return r-l+1;
            }
            else{
                char a = s[l];
                while(l <= r && s[l] == a) l++;
                while(l <= r && s[r] == a) r--;
            }
        }
        return r-l+1;
    }
};