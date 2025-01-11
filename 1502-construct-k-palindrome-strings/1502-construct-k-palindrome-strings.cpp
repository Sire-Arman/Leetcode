class Solution {
public:
    bool canConstruct(string s, int k) {
        int maxPos = 0, oddC =0;
        vector<int> freq(26);
        for(auto &it : s){
            freq[it-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]&1) oddC++;
            maxPos += freq[i];
        }
        if(oddC > k || k > maxPos) return false;
        return true;
    }
};