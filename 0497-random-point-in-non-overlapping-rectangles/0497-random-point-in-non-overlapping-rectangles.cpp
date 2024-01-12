class Solution {
public:
    int i,j;
    int a,b,c,d;
    int index;
    vector<vector<int>> rects;
    Solution(vector<vector<int>>& rect) {
        index=0;
        this-> rects = rect;
        a = rects[index][0];
        b = rects[index][1];
        c = rects[index][2];
        d = rects[index][3];
        i = a,j =b;
    }
    
    vector<int> pick() {
        
        auto val = {i,j};
        j++;
        if(j == d+1){
            i++;
            j=b;
            if(i==c+1){
                index++;
                if(index == rects.size()){
                    index = 0;
                }
                a = rects[index][0];
                b = rects[index][1];
                c = rects[index][2];
                d = rects[index][3];
                i = a,j =b;
            }
        }
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */