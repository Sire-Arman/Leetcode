class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end());
        int n = c.size();
        int h=1;
        for(int i = n-1;i>=0;i--){
            if(c[i]<h){
                break;
            }
            else{
                h++;
            }
        }
        return h-1;
    }
};