class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int x =0;
        for(auto &it : s){
            if(it == ')') x--;
            else if(it == '(') x++;
            if(x<0){
                it = 'A';
                x++;
            }
        }
        x=0;
        for(int i = s.size()-1;i>=0;i--){
                if(s[i] == ')') x++;
                else if(s[i] == '(') x--;
                if(x<0){
                    s[i] = 'A';
                    x++;
                }
        }
        string temp = "";
        for(auto it : s){
            if(it != 'A') temp+= it;
        }
        return temp;
    }
};