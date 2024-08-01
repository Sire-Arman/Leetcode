class Solution {
public:
    int countSeniors(vector<string>& d) {
        int ans =0;
        for(auto it : d){
            int l = stoi(it.substr(11,2));
            if(l>60) ans++;
        }
        return ans;
    }
};