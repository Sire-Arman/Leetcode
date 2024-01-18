class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        int dist =0;
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                if(sqrt(pow(x-i,2) + pow(y-j,2))<=r){
                    return true;
                }
            } 
        }
        return false;
    }
};