class Solution {
public:
    bool solve(string s, int i, int bal, vector<vector<int>>& dp){
        if(i == s.size()){
            if(bal ==0) return true;
            else return false;
        }
        if(dp[i][bal] != -1) return dp[i][bal];
        bool ans = false;
        if(s[i] == '(') {
            ans = ans || solve(s,i+1,bal+1,dp);
        }
        else if(s[i] == ')'){
            if(bal<=0) return dp[i][bal] = ans;
            ans = ans || solve(s,i+1,bal-1,dp);
        }
        else{
//             case 1
            // st.push('(');
            ans = ans || solve(s,i+1,bal+1,dp);
//             case 2
            ans = ans || solve(s,i+1,bal,dp);
//             case 3
            if(bal > 0) ans = ans || solve(s,i+1,bal-1,dp);
        }
        return dp[i][bal] = ans;
    }
    bool checkValidString(string s) {
        stack<char> st;
        vector<vector<int>> dp(101,vector<int>(101,-1));
        // int star =0;
        // for(auto it : s){
        //     if(it == '('){
        //         st.push(it);
        //     }
        //     else if(it == ')'){
        //         if(st.empty() && star == 0) return false;
        //         else if (st.empty()){
        //             star--;
        //         }
        //         else{
        //             st.pop();
        //         }
        //     }
        //     else{
        //         star++;
        //     }
        // }
        // while(!st.empty() && star){
        //     st.pop();
        //     star--;
        // }
        // if(!st.empty()) return false;
        // return true;
        return solve(s,0,0,dp);
    }
};