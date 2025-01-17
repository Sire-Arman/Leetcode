class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int n=d.size();
        bool ans = 0;
        for(int i=0;i<n;i++){
           ans = ans^d[i];
        }
        return !ans;
    }
};