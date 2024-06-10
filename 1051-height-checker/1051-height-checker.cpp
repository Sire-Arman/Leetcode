class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> h (heights.begin(), heights.end());
        int cnt =0,n=h.size();
        sort(h.begin(), h.end());
        for(int i=0;i<n;i++){
            if(h[i] != heights[i]) cnt++;
        }
        return cnt;
    }
};