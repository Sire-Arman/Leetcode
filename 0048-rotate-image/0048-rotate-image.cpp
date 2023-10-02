class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        stack<int> ans;
        int n = matrix.size();
        for(int i = n-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                ans.push(matrix[j][i]);
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = n-1;j>=0;j--){
                matrix[i][j] = ans.top();
                ans.pop();
            }
        }
        
    }
};