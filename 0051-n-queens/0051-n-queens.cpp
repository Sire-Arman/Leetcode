class Solution {
public:
    bool safe(int row,int col,vector<string> &board, int n){
        int tr = row,tc = col;
        while(row>=0 && col >=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        row = tr;
        col = tc;
        while(col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        row = tr;
        col = tc;
        while(row<n && col >=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int n,int col,vector<string> &board,vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(board);
            return; 
        }
        for(int i=0;i<n;i++){
            if(safe(i,col,board,n)){
                board[i][col] = 'Q';
                solve(n,col+1,board,ans);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        vector<vector<string>> ans;
        solve(n,0,board,ans);
        return ans;
    }
};