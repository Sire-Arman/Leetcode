class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(),m=word2.size();
        vector<int> ans;
        bool swap = true;
        vector<int> suff(n+1);
        suff[n] = 0;
        int j = m-1;
        for(int i=n-1;i>=0;i--){
            suff[i] = suff[i+1];
            if(j>=0 && word2[j]== word1[i]){
                suff[i]++;
                j--;
            }
        }
        j = 0;
        for(int i =0;i<n && j<m;i++){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(swap && suff[i] >= m-1-j){
                ans.push_back(i);
                swap = false;
                j++;
            }
        }
        if(j==m) return ans;
        return {};
    }
};