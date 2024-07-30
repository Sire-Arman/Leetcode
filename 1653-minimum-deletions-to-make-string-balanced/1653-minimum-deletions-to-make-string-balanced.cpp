class Solution {
public:
    int minimumDeletions(string s) {
        int a =0,b=0;
        int i=0;
        stack<int> st;
        int n = s.size();
          int c =0;
        while(i<n){
            while(!st.empty() && st.top() == 'b' && s[i] == 'a'){
                c++;
                i++;
                st.pop();
            }
            st.push(s[i]);
            i++;
            
        }
        return c;
    }
};