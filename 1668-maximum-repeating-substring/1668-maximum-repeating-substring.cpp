class Solution {
public:
    int findConsecutive(string &seq, string& word, int i){
        if(i+word.size()>seq.size()) return 0;
        if(seq.substr(i,word.size()) == word){
            return 1+findConsecutive(seq,word,i+word.size());
        }
        return 0;
    }
    int backtrack(string& seq, string& word, int i, vector<int>& dp){
        if(i>=seq.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int consec = findConsecutive(seq,word,i);
        int skip = backtrack(seq,word,i+1,dp);
        return max(skip,consec);
    }
    int maxRepeating(string seq, string word) {
        vector<int> dp(seq.size()+1,-1);
        return backtrack(seq,word,0,dp);
    }
};