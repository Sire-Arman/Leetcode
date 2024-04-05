class Solution {
public:
    string makeGood(string s) {
        string temp = "";
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!st.empty() && abs(st.top()-s[i]) == 32){
                st.pop(); continue;
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()) {temp += st.top();st.pop();}
        reverse(temp.begin(),temp.end());
            return temp;
    }
};