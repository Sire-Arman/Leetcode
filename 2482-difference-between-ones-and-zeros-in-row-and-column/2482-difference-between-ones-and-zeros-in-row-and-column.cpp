class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        map<int,pair<int,int>> rows;
        map<int,pair<int,int>> cols;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    rows[i].first++;
                }
                else{
                    rows[i].second++;
                }
            }
        }
        for(int j=0;j<grid[0].size();j++){
            for(int i=0;i<grid.size();i++){
                if(grid[i][j] == 0){
                    cols[j].first++;
                }
                else{
                    cols[j].second++;
                }
            }
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j] = (rows[i].second+cols[j].second) -rows[i].first - cols[j].first;
            }
        }
        return grid;
    }
};