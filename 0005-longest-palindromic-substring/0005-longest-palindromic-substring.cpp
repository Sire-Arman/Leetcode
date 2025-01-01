class Solution {
public:
string expand(int l, int r, string s){
    while(l>=0 && r <s.size() && s[l] == s[r]){
        l--;
        r++;
    }
    return s.substr(l+1,r-l-1);
}
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        
        string ans = "";
        for(int i=0;i<n-1;i++){
            string odd = expand(i,i,s);
            string even = expand(i,i+1,s);
            if(ans.length()< odd.length()){
                ans = odd;
            }
            if(ans.length() < even.length()){
                ans = even;
            }
        }
        return ans;
    }
};