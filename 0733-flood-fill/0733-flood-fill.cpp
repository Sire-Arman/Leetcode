class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int cur){
        if(sr<0 || sc <0 || sr>=image.size() || sc >= image[0].size() || image[sr][sc] == color || image[sr][sc] != cur) return;
        image[sr][sc] = color;
        dfs(image, sr+1,sc,color,cur);
        dfs(image, sr-1,sc,color,cur);
        dfs(image, sr,sc-1,color,cur);
        dfs(image, sr,sc+1,color,cur);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};