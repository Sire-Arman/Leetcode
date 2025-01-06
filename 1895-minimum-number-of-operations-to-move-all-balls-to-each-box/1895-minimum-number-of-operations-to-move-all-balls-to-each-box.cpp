class Solution {
public:
    vector<int> minOperations(string b) {
        vector<int> ans(b.size());
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b.size();j++){
                if(b[j] == '1') ans[i] += abs(j-i); 
            }
        }
        return ans;
    }
};