class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> opr;
        stack<char> opn;
        for(auto it : exp){
            if(it=='&'|| it=='|' || it =='!'){
                opr.push(it);
            }
            else if(it == 't'||it=='f'||it=='('){
                opn.push(it);
            }
            else if(it ==')'){
                char op = opr.top();
                opr.pop();
                
                if(op =='&'){
                    int ans =1;
                    while(opn.top() != '('){
                        if(opn.top()=='t'){
                            ans &=1;
                        }
                        else{
                            ans&=0;
                        }
                        opn.pop();
                    }
                    opn.pop();
                    if(ans) opn.push('t');
                    else opn.push('f');
                }
                else if (op=='|'){
                    int ans =0;
                     while(opn.top() != '('){
                        if(opn.top()=='t'){
                            ans |=1;
                        }
                        else{
                            ans|=0;
                        }
                        opn.pop();
                    }
                    opn.pop();
                    if(ans) opn.push('t');
                    else opn.push('f');
                }
                else{
                    int ans =0;
                    if(opn.top()=='f'){
                        ans=1;
                    }
                    opn.pop();
                    opn.pop();
                    if(ans) opn.push('t');
                    else opn.push('f');
                }
            }
        }
        return opn.top()=='t';
    }
};