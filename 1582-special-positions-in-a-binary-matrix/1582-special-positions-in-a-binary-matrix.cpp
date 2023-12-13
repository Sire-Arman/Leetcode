class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        map<int,int> rows;
        map<int,int> col;
        int cnt=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                rows[i] += mat[i][j];
            }
        }
        for(int j=0;j<mat[0].size();j++){
            for(int i=0;i<mat.size();i++){
                col[j] += mat[i][j];
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1 && rows[i] == 1 && col [j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};