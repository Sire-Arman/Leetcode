class Solution {
public:
    bool backspaceCompare(string s, string t) {
       stack<int> s1,s2;
        for(auto it : s){
            if(it == '#' && !s1.empty()){
                s1.pop();
            }
            else if(it == '#' && s1.empty()){
                continue;
            }
            else{
                s1.push(it);
            }
        }
        s="";
        while(!s1.empty()){
            string a(1,s1.top());
            s += a;
            s1.pop();
        }
        for(auto it : t){
            if(it == '#' && !s2.empty()){
                s2.pop();
            }
            else if(it == '#' && s2.empty()){
                continue;
            }
            else{
                s2.push(it);
            }
        }
        t="";
        while(!s2.empty()){
            string b(1,s2.top());
            t+= b;
            s2.pop();
        }
        return s==t;
    }
};