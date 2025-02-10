class Solution {
public:
    string clearDigits(string s) {
        stack<int> st;
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            if(isdigit(s[i])){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    s[i]='A';
                    s[st.top()]='A';
                    st.pop();
                }
            }
        }
        string ans = "";
        for(auto it : s){
            if(it != 'A'){
                ans += it;
            }
        }
        return ans;
    }
};