class Solution {
public:
    bool solve(vector<vector<char>>& b, string &w, int i, int j, int ind){
        if(ind == w.size()) return true;
        if(i>=b.size() || j >= b[0].size() || i<0 || j<0 ||  b[i][j] != w[ind]) return false;
        bool ans = false;
            char c = b[i][j];
            b[i][j] = '*';
//             Include
            ans = solve(b,w,i+1,j,ind+1) || solve(b,w,i,j+1,ind+1);
            ans = ans || (solve(b,w,i-1,j,ind+1) || solve(b,w,i,j-1,ind+1));
            b[i][j] = c;
        return ans;  
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(solve(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};