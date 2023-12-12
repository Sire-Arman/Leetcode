class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int cnt=0;
        for(auto it :s){
            st.push(it);
            if(it == '*'){
                    st.pop();
                st.pop();
            }  
        }
        string ans ="";
        while(!st.empty()){
            ans+= st.top();
            st.pop();     
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};