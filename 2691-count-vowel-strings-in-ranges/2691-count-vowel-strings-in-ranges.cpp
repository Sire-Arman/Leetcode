class Solution {
public:
bool isVowel(char ch){
    if(ch == 'a'|| ch=='e' || ch == 'i' || ch=='o'||ch =='u') return true;
    return false;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        int n = words.size();
        vector<int> prefix(n+1);
        for(int i=1;i<=n;i++){
            int c = words[i-1].size();
            prefix[i] = prefix[i-1];
            if(isVowel(words[i-1][c-1]) && isVowel(words[i-1][0])) prefix[i]++;
        }
        int s = q.size();
        vector<int> ans(s);
        for(int i=0;i<s;i++){
            ans[i] = prefix[q[i][1]+1]-prefix[q[i][0]];
        }
        return ans;
    }
};