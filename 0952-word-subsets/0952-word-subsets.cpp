class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26);
        vector<string> res;
        for(auto &it : words2){
            vector<int> curr(26);
            for(auto & i: it){
                curr[i-'a']++;
            }
            for(int i=0;i<26;i++){
                freq[i] = max(freq[i],curr[i]);
            }
        }
        for(auto &it : words1){
            vector<int> cur(26);
            for(auto& i : it){
                cur[i-'a']++;
            }
            bool ans = true;
            for(int i=0;i<26;i++){
                if(cur[i]<freq[i]) {ans = false;break;}
            }
            if(ans) res.push_back(it);
        }
        return res;
    }
};