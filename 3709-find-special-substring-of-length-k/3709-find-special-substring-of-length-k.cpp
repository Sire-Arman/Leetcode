class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int l =1;
        for(int i=1;i<s.size();i++){
            if(s[i-1] == s[i]){
                l++;
            }
            else{
                if(l==k) return true;
                l=1;
            }
        }
        return l==k;
    }
};