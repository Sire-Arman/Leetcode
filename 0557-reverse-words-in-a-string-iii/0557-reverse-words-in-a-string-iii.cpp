class Solution {
public:
    string reverseWords(string s) {
        int index =0;
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                reverse(s.begin()+index,s.begin()+i);
                index = i+1;
            }
        }
    reverse(s.begin()+index,s.end());
                                   
    return s;
    }
};