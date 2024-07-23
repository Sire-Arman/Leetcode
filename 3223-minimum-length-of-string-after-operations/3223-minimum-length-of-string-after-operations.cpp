class Solution {
public:
    int minimumLength(string s) {
        vector<int> chars(26);
        for(auto it : s){
            chars[it-'a']++;
        }
        int ans =0;
        for(auto it: chars){
            if(it>=3){
                if(it%2 == 0) it = 2;
                else it = 1;
            }
            ans+= it;
        }
        return ans;
    }
};