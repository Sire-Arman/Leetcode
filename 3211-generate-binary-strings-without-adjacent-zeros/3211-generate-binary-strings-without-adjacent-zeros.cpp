class Solution {
public:
    void solve(int n, int prev, string t, vector<string>& ans){
        if(n == 0) {
            ans.push_back(t);
            return;
        }
        if(prev == 0){
            solve(n-1,1,t+'1',ans);
        }
        else{
            solve(n-1,0,t+'0',ans);
            solve(n-1,1,t+'1',ans);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(n,-1,"",ans);
        return ans;
        
    }
};