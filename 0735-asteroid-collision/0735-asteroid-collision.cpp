class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<a.size();i++){
            if(st.empty()) st.push(a[i]);
            else if(a[i]<0 && st.top()>0){
                while(!st.empty() && st.top()>0 && abs(a[i])>st.top()){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(a[i])){
                    st.pop();
                }
                else if(st.empty() || st.top() <0){
                    st.push(a[i]);
                }
                
            }
            else{
                st.push(a[i]);
            }
        }
              while(!st.empty()){
                  ans.push_back(st.top());
                  st.pop();
              } 
                   reverse(ans.begin(),ans.end());
                   return ans;
    }
};