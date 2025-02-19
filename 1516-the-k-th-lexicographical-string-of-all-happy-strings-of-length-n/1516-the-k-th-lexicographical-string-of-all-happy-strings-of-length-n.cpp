class Solution {
public:
    void solve(int i, char prev, int n,vector<string>& st,string cur){
        if(i>n) return;
        if(i==(n)) {
            cout<<cur<<' ';
            st.push_back(cur);
            return;
        }
        if(prev != 'a'){
        solve(i+1,'a',n,st,cur+'a');   
        }
        if(prev != 'b'){
        solve(i+1,'b',n,st,cur+'b');   
        }
        if(prev != 'c'){
        solve(i+1,'c',n,st,cur+'c');   
        }
    }
    string getHappyString(int n, int k) {
        vector<string> st;
        solve(0,'A',n,st,"");
        return k>st.size() ? "":st[k-1];
    }
};