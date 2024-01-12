class Solution {
public:
    bool check(char ch){
        if( ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'
           ||ch == 'u'||ch == 'A'||ch == 'E'||ch == 'I'
           ||ch == 'O'||ch == 'U') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int i=0,j=s.size()-1;
        int ci=0;
        while(i<j){
            if(check(s[i])) ci++;
            if(check(s[j]))ci--;
            i++;
            j--;
        }
        return (ci==0);
    }
};