class Solution {
public:
    bool canBeValid(string s, string l) {
        stack<int> open,unl;
        int n = l.size();
        if(n&1) return false;
        int c =0;
        for(int i=0;i<n;i++){
            if(l[i]=='0'){
                unl.push(i);
            }
            else{
                if(s[i]==')'){
                    if(!open.empty()){
                        open.pop();
                    }
                    else if (!unl.empty()){
                        unl.pop();
                    }
                    else return false;
                }
                else{
                    open.push(i);
                }
            }
        }
        while(!unl.empty() && !open.empty()){
            if(open.top() < unl.top()){
                open.pop();
                unl.pop();
            }
            else{
                return false;
            }
        }
        return open.empty();
    }
};