class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        // int ans =0;
        int n = s.size(), m=t.size();
        for(int i=0;i<n;i++){
            if(j==t.size()) break;
            else{
                if(s[i]==t[j]) j++;
            }
        }
        return m-j;
    }
};