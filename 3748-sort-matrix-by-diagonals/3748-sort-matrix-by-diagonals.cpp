class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, multiset<int>> diagMap;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diagMap[i - j].insert(grid[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i-j>=0){
                grid[i][j] = *next(diagMap[i-j].end(),-1);
                diagMap[i - j].erase(next(diagMap[i - j].end(),-1));
                }
                else{
                    grid[i][j] = *diagMap[i - j].begin();
                    diagMap[i - j].erase(diagMap[i - j].begin());
                }
            }
        }

        return grid;
    }
    static bool cmp(int& a, int &b) {return a>b;}
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        return solve(grid);
    }
};