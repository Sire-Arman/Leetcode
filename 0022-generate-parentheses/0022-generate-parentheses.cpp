class Solution {
public:
void backtrack(int n, int i, int bal, string s,vector<string>& ans){
    if(i >= 2*n){
        if(bal == 0){
            ans.push_back(s);
        }
        return;
}
    if (bal > 0) backtrack(n,i+1,bal-1,s+")",ans);
    backtrack(n,i+1,bal+1,s+"(",ans);
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(n,0,0,"",ans);
        return ans;
    }
};