class Solution {
public:
    int lengthOfLastWord(string s) {
        int len =0;
        int prev =0;
        for(int i =0;i<s.size();i++){
            if(s[i] == ' ' && len != 0){
                prev = len;
                len =0;
            }
            else if(s[i] != ' '){
                len++;
            }
        }
        if(len) return len;
        else return prev;
    }
};