class Solution {
public:
    int minChanges(string s) {
        int cnt =0;
        int len =1;
        for(int i=1;i<s.size();i++){
               if(s[i] != s[i-1] && len%2 != 0){
                   cnt++;
                   len =0;
               } 
            else if (s[i] != s[i-1] && len%2 == 0){
                len =1;
            }
            else{
                len++;
            }
        }
        return cnt;
    }
};