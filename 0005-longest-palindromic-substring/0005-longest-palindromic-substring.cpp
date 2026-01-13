class Solution {
public:
    string isEPalindromic(string& s,int i){
        int n = s.size();
        int j = i+1;
        string ans = "";
        while(i>=0 && j<n){
            if(s[i] != s[j]) break;
            ans = s.substr(i,j-i+1);
            j++;
            i--;
        }
       return ans;
    }
    string isOPalindromic(string& s,int i){
        int n = s.size();
        int j = i;
        string ans = s.substr(i,1);
        while(i>=0 && j<n){
            if(s[i] != s[j]) break;
            ans = s.substr(i,j-i+1);
            j++;
            i--;
        }
       return ans;
    }
    // string solve(string& s, int i, int j){
    // }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i =0;i<s.size();i++){
            string res = isEPalindromic(s,i);
            string res2 = isOPalindromic(s,i);
            if(res.size()>ans.size() || res2.size()>ans.size()){
                if(res2.size()>res.size()){
                    ans=res2;
                }
                else ans = res;
            }
        }
        return ans;
    }
};