class Solution {
public:
    int maxDepth(string s) {
        int ans = 0,cnt=0;
        for(auto it : s){
            if(it == '('){
                cnt++;
            }
            ans = max(ans,cnt);
            if(it == ')') cnt--;
        }
        return ans;
    }
};