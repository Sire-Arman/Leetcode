class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        map<int,bool> r;
        map<int,bool> c;
            
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    r[i] = true;
                    c[j] = true;
                    
                }
            }
        }
        for(int i=0;i<row;i++){
            if(r[i]){
               for(int j=0;j<col;j++){
                matrix[i][j] =0;
               }
            }
        }
        for(int j=0;j<col;j++){
            if(c[j]){
               for(int i=0;i<row;i++){
                matrix[i][j] =0;
               }
            }
        }
    }
};