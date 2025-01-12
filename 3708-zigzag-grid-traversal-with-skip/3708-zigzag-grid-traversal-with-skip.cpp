class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<int> ans;
        int i=0,j=0;
        bool s = true;
        while(i<r){
            if(i&1){
                j=c-1;
                while(j>=0){ if(s){ans.push_back(grid[i][j]);} s=!s;j--;}
            }
            else{
                j=0;
                while(j<c) {if(s){ans.push_back(grid[i][j]);} s = !s;j++;}
            }
            i++;
        }
        return ans;
    }
};