class Solution {
public:
    pair<int,int> dfs(vector<vector<int>>& land, int r,int c){
        if(r <0 || c<0 || r>=land.size() || c>=land[0].size() || land[r][c] == 0) return {0,0};
        int mr =r,mc = c; 
        land[r][c] = 0;
        auto x = dfs(land,r+1,c);
        auto y = dfs(land,r,c+1);
        mr = max(x.first, max(mr, y.first));
        mc = max(x.second,max(mc,y.second));
        return {mr,mc};
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        for(int i =0;i<land.size();i++){
            for(int j =0;j<land[0].size();j++){
                vector<int> ans;
                if(land[i][j] == 1){
                    ans.push_back(i);
                    ans.push_back(j);
                    auto a = dfs(land,i,j);
                    ans.push_back(a.first);
                    ans.push_back(a.second);
                }
                if(ans.size()) res.push_back(ans);
            }
        }
        return res;
    }
};