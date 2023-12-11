class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int> ,int> mp;
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            mp[grid[i]]++;
        }
        for(int i=0;i<grid.size();i++){
            vector<int> temp;
            for(int j=0;j<grid.size();j++){
                temp.push_back(grid[j][i]);
            }
            cnt+= mp[temp];
        }
        return cnt;
    }
};