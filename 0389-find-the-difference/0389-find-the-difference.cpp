class Solution {
public:
    char findTheDifference(string s, string t) {
       int x=0,y=0;
        for(auto it: s){
            x=x^(it-'0');
        }
        for(auto it:t){
            y = y^ (it-'0');
        }
        y=y^x;
        return y+'0';
    }
};